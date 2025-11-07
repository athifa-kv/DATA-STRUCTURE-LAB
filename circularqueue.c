#include<stdio.h>
int q[5],i,item,front=-1,rear=-1;
void enqueue(int item)
{
    if((rear+1)%5==front)
    {
        printf("The queue is full\n");
    
    }
    else
    {
        if((rear==-1)&&(front==-1))
        {
            front=(front+1)%5;
            rear=(rear+1)%5;
        }
        else
        {
            rear=(rear+1)%5;
        }
        q[rear]=item;
    }
}
void dequeue()
{
    if((front==-1)&&(rear==-1))
    {
        printf("Queue is empty\n");
    }
    else
    {
        if(front==rear)
        {
            printf("The deleted item is %d",q[front]);
            front=-1;
            rear=-1;
        }
        else
        {
            printf("The deleted item is %d",q[front]);
            front=(front+1)%5;
        }    
    }
}
void display()
{
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        printf("%d ",q[i]);
    }
    else
    {
        for(i=front;i<5;i++)
           printf("%d ",q[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",q[i]);
    }
}
void main()
{
    int choice;
    do
    {
        printf("Enter the choice");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the item to be inserted");
                scanf("%d",&item);
                enqueue(item);
                break;
            }
            case 2:
            {
                dequeue(item);
                break;
            }
            case 3:
            {
                display(item);
                break;
            }
            case 4:
            {
                printf("Exit");
                break;
            }
            default: printf("Invalid choice");
        }
    }
    while(choice!=4);
}