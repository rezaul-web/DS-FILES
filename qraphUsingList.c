#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertex;
    struct Node **list;
};

struct Node *CreateNode(int value)
{
    struct Node *t = malloc(sizeof(struct Node));
    t->vertex = value;
    t->next = NULL;
    return t;
}

struct Graph *CreateGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertex = vertices;
    graph->list = malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->list[i] = NULL;
    }

    return graph;
}

void AddEdge(struct Graph *graph, int s, int d)
{
    struct Node *newNode = CreateNode(d);
    newNode->next = graph->list[s];
    graph->list[s] = newNode;

    newNode = CreateNode(s);
    newNode->next = graph->list[d];
    graph->list[d] = newNode;
}

void PrintGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertex; v++)
    {
        struct Node *temp = graph->list[v];
        printf("Adjacency list of vertex %d\n head ", v);
        while (temp)
        {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph *graph, int start, bool visited[])
{
    printf("Depth-First Search (DFS) traversal starting from vertex %d: ", start);

    struct Node *stack[MAX_VERTICES]; // Stack for DFS
    int top = -1;

    visited[start] = true;
    printf("%d ", start);
    stack[++top] = CreateNode(start);

    while (top != -1)
    {
        struct Node *current = stack[top--];
        int vertex = current->vertex;
        struct Node *temp = graph->list[vertex];

        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                printf("%d ", adjVertex);
                stack[++top] = CreateNode(adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void BFS(struct Graph *graph, int start, bool visited[])
{
    printf("Breadth-First Search (BFS) traversal starting from vertex %d: ", start);

    struct Node *queue[MAX_VERTICES]; // Queue for BFS
    int front = -1, rear = -1;

    visited[start] = true;
    printf("%d ", start);
    queue[++rear] = CreateNode(start);

    while (front != rear)
    {
        struct Node *current = queue[++front];
        int vertex = current->vertex;
        struct Node *temp = graph->list[vertex];

        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                printf("%d ", adjVertex);
                queue[++rear] = CreateNode(adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    struct Graph *graph = CreateGraph(n);
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printf("1. Add an edge\n2. Print Graph \n3. DFS\n4. BFS\n5. Exit\n\n");
    int choice = 0;
    while (choice != 5)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter values of a and b : ");
            int a, b;
            scanf("%d %d", &a, &b);
            AddEdge(graph, a, b);
            break;
        case 2:
            PrintGraph(graph);
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            printf("Enter the starting vertex for DFS: ");
            scanf("%d", &a);
            DFS(graph, a, visited);
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            printf("Enter the starting vertex for BFS: ");
            scanf("%d", &a);
            BFS(graph, a, visited);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
