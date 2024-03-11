#include<stdio.h>
#include<stdlib.h>

struct stack{
int top;
int size;
int *S;
};
struct stack *st;

void Create()
{
    st=(struct stack *)malloc(sizeof(struct stack));
    printf("Enter the size of stack : ");
    scanf("%d",&st->size);
    st->S=(int *)malloc(st->size*sizeof(int));
    st->top=-1;
    printf("Stack is created/n");
}
void Push(){
    if(st->top==st->size-1)
        printf("Overflow\n");
else{
    printf("Enter data for insertion : ");
int value=0;
scanf("%d",&value);
st->top++;
st->S[st->top]=value;
}

}
void pop(){
if(st->top==-1)
    printf("\nUnderflow");
else {
    int x=-1;
   x=st->S[st->top];
   st->top--;
   printf("deleted value is %d\n",x);
}
}
void Display()
{
    if(st->top==-1)
        printf("Nothing to display \n");
    else {
        printf("Printing data in the stack : ");

        for(int i=st->top;i>=0;i--)
            printf("%d\t",st->S[i]);
    }
}
void top()
{
    if(top==-1)
        printf("Stack is empty ");
    else
    {
        printf("Top element is %d\n",st->S[st->top]);
    }
}
int main(){
int choice;
    while(choice != 6)
    {

        printf("\n1.Create\n2.Push\n3.POP\n4.Top\n5.Show\n6.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1:
           Create();
            break;
            case 2:
            Push();
            break;
            case 3:
            pop();
            break;
            case 4:
            top();
            break;
            case 5: Display();
            break;
            case 6:exit(0);
            break;
            default:
            printf("\nEnter valid choice??\n");
        }
    }
}



