#include<stdio.h>
#include<stdlib.h>
#define MAXPQ 100

struct pqueue{
    int item[MAXPQ];
    int rear;
};

struct pqueue pq;

void pqinsert(struct pqueue *pq,int x)
{
    if(pq->rear>=MAXPQ)
    {
        printf("Priority queue Overflow\n");
        exit(1);
    }
    pq->item[pq->rear]=x;
    (pq->rear)++;
}

int pqdeleteMin(struct pqueue *pq)
{
    if(pq->rear == 0)
    {
        printf("Priority queue Underflow\n");
        exit(1);
    }
    int min_index = 0;
    for(int i = 1; i < pq->rear; i++)
    {
        if(pq->item[i] < pq->item[min_index])
            min_index = i;
    }
    int deleted_item = pq->item[min_index];
    for(int i = min_index; i < pq->rear - 1; i++)
    {
        pq->item[i] = pq->item[i+1];
    }
    (pq->rear)--;
    return deleted_item;
}
int pqdeleteMax(struct pqueue *pq)
{
    if(pq->rear == 0)
    {
        printf("Priority queue Underflow\n");
        exit(1);
    }
    int max_index = 0;
    for(int i = 1; i < pq->rear; i++)
    {
        if(pq->item[i] > pq->item[max_index])
            max_index = i;
    }
    int deleted_item = pq->item[max_index];
    for(int i = max_index; i < pq->rear - 1; i++)
    {
        pq->item[i] = pq->item[i+1];
    }
    (pq->rear)--;
    return deleted_item;
}

void display(struct pqueue pq)
{
    if(pq.rear == 0)
    {
        printf("Priority queue is empty\n");
        return;
    }
    printf("Priority queue elements: ");
    for(int i = 0; i < pq.rear; i++)
    {
        printf("%d ", pq.item[i]);
    }
    printf("\n");
}

int main()
{
    pq.rear = 0;
    int choice, element;

    while(1)
    {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Minimum Element\n");
        printf("3. Delete Maximum Element\n");
        printf("4. Display Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                pqinsert(&pq, element);
                printf("Element %d inserted successfully.\n", element);
                break;
            case 2:
                if(pq.rear == 0)
                {
                    printf("Priority queue is empty. Cannot delete.\n");
                }
                else
                {
                    int deleted_item = pqdeleteMin(&pq);
                    printf("Minimum Element %d deleted successfully.\n", deleted_item);
                }
                break;
                case 3:
                if(pq.rear == 0)
                {
                    printf("Priority queue is empty. Cannot delete.\n");
                }
                else
                {
                    int deleted_item = pqdeleteMax(&pq);
                    printf("Maximum Element %d deleted successfully.\n", deleted_item);
                }
                break;
            case 4:
                display(pq);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please enter a valid option.\n");
        }
    }
    return 0;
}
