//STACK USING AN ARRAY
#include<stdio.h>
 int top=-1;
int *top_ptr=&top;
void push(int st[],int e,int m)
{
    if(*top_ptr==m-1)
    {
        printf("Overflow");
        return;
    }
    //printf("%d\n",top);
    st[*top_ptr+1]=e;
    *top_ptr=*top_ptr+1;
}
void Print(int st[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",st[i]);

    }

}
void pop()
{
    if(*top_ptr==-1)
    {
        printf("Underflow");
        return;
    }
    *top_ptr=*top_ptr-1;

}

int main()
{
    int max,ele,num,i;
    printf("Enter the max number of elements\n");
    scanf("%d",&max);
    int stack[max];

//int *top_ptr=&top;
    printf("Enter the number of elements you want to enter \n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
         printf("Enter the element\n");
          scanf("%d",&ele);
          push(stack,ele,max);

    }
    Print(stack,num);
   /**  for(i=0;i<num;i++)
    {
        printf("%d\n",stack[i]);

    }
    */
    return 0;
}
