#include<stdio.h>
#include<stdlib.h>

struct dequeue{
    int front;
    int rear;
    int size;
    int *A;
};

struct dequeue *dq;

void Create() {
    dq = (struct dequeue *)malloc(sizeof(struct dequeue));
    int n;
    printf("Enter the size of the dequeue : ");
    scanf("%d", &n);
    dq->size = n;
    printf("Created successfully\n");
    dq->A = (int*)malloc(sizeof(int) * dq->size);
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty() {
    if(dq->front == -1 && dq->rear == -1)
        return 1;
    return 0;
}

void AddFront() {
    int value = 0;
    printf("Enter the value : ");
    scanf("%d", &value);

    if ((dq->front == 0 && dq->rear == dq->size - 1) || (dq->rear == (dq->front - 1) % (dq->size - 1))) {
        printf("Deque is full, cannot add element at front\n");
        return;
    } else if (isEmpty()) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->size - 1;
    } else {
        dq->front = dq->front - 1;
    }
    dq->A[dq->front] = value;
    printf("Element added successfully \n");
}

void AddRear() {
    int value = 0;
    printf("Enter the value : ");
    scanf("%d", &value);

    if ((dq->front == 0 && dq->rear == dq->size - 1) || (dq->rear == (dq->front - 1) % (dq->size - 1))) {
        printf("Deque is full, cannot add element at rear\n");
        return;
    } else if (isEmpty()) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == dq->size - 1) {
        dq->rear = 0;
    } else {
        dq->rear = dq->rear + 1;
    }
    dq->A[dq->rear] = value;
    printf("Element added successfully \n");
}

void DeleteFront() {
    if (isEmpty()) {
        printf("Deque is empty, cannot delete from front\n");
        return;
    } else if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == dq->size - 1) {
        dq->front = 0;
    } else {
        dq->front = dq->front + 1;
    }
    printf("Element deleted from front successfully\n");
}

void DeleteRear() {
    if (isEmpty()) {
        printf("Deque is empty, cannot delete from rear\n");
        return;
    } else if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->size - 1;
    } else {
        dq->rear = dq->rear - 1;
    }
    printf("Element deleted from rear successfully\n");
}

void Display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", dq->A[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % dq->size;
    }
    printf("\n");
}

int main() {
    int choice;
    while (choice != 6) {
        printf("\n1.Create\n2.Add Front\n3.Add rear\n4.Delete Front\n5.Delete Rear\n6.Show\n7.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                Create();
                break;
            case 2:
                AddFront();
                break;
            case 3:
                AddRear();
                break;
            case 4:
                DeleteFront();
                break;
            case 5:
                DeleteRear();
                break;
            case 6:
                Display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice\n");
        }
    }
    return 0;
}
