#include<stdio.h>
#include<stdbool.h>
int front=-1;
int rear=-1;
bool is_empty();
bool is_full(int lim);
void enqueue(int n,int lim,int q[])
{
    if(is_full(lim))
    {
        printf("Queue is full\n");
    }
    else if(is_empty())
    {
        front=0;
        rear=0;
    }
    else
    {
            rear=(rear+1)%lim;
    }
    q[rear]=n;

}

void dequeue(int lim)
{

    if(is_empty())
    {
        printf("The queue is empty");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
            front=(front+1)%lim;
    }


}




bool is_empty()
{
    if(front==-1&&rear==-1)
    {
        return true;
    }
    else
        {
        return false;
    }

}

bool is_full(int lim)
{
    if((rear+1)%lim==front)
    {
        return true;
    }
    else
        {
        return false;
    }

}

void traverse(int q[])
{
int i;
if (is_empty())
printf("Queue is empty\n");
else
{
printf("\nQueue is :\n");
for(i=front;i<=rear;i++)
printf("%d ",q[i]);
}

}

int main()
{
    int limit,i,num;
    printf("Enter the number of elements you want to enter \n");
    scanf("%d",&limit);
    int queue[limit];
    for(i=0;i<limit;i++)
    {
        printf("Enter the element you want to enter \n");
        scanf("%d",&num);
        enqueue(num,limit,queue);
    }
    traverse(queue);
    dequeue(limit);
    traverse(queue);

    return 0;
}
