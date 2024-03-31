#include <stdio.h>
#define row 5
#define col 5

int adjecencyMatrix[row][col];

void addEdge(int u, int v)
{
    if (u >= 0 && u < row && v >= 0 && v < col)
    {
        adjecencyMatrix[u][v] = 1;
        printf("Successfully added \n");
    }
    else
        printf("Invalid index\n");
}

int main()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            adjecencyMatrix[i][j] = 0;
        }
    }
    printf("1.Add Edge\n2.Print the adjecency matrix \n");
    int choice;
    while (choice != 4)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter row and column : ");
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b);

            break;
        case 2:
            printf("Printing adjecent list : \n");
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    printf("%d ", adjecencyMatrix[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice \n");
        }
    }
}