
/**
 This program will contain the blueprint and the functions of a singly linked list
*/
/**
    Main function=line 118
    Node blue print=line 12-16
    Print function=line 33-41
    Function add_begin=line 48
    function insert= line 65
    function search=lines 96-107
    function
*/

/**
    Notes and questions
        {
    1-char needs & in scanf
    2- printf("Enter the number of things you want to enter\n");
       scanf("%d",&num);
        printf("Enter the how you would like to enter the data\n");
        printf("Press e if you want it from the end \tPress f if you want it from the beginning \n");

        scanf(" %c",&choice);====>Why is a space needed here
        }
*/
#include<stdio.h>
#include<stdlib.h>
//Node blue print
struct node
{
    int data;
    struct node*link;
};
struct node *head=NULL;
//head=NULL not possible why ??

void Print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
//To add elements from the beginning
void add_begin(int x)
{

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
      if(head==NULL)
         {
             head=temp;
             temp->link=NULL;//IMPORTANT MADE MISTAKE HERE
             return;//Acts like a break statement for the function ie. exists the function

         }

    temp->link=head;
    head=temp;
}
//Function to insert at a specific position
void insert(int in,int d,int n)
{
    int i;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    if(in>n || in<1)
    {
        printf("You have not entered a proper index\n");

    }
       struct node *temp1=head;
    for(i=1;i<in;i++)
    {
        temp1=temp1->link;
    }
    temp->link=temp1->link;//Because temp 1 will have link to next node
    temp1->link=temp;
    Print();
}
//To delete a node
void del(int ind,int n)
{
   int i;
        struct node *d=(struct node*)malloc(sizeof(struct node));
     struct node *temp1=head;
    for(i=1;i<ind;i++)
    {
        temp1=temp1->link;
        if(temp1==NULL)
        {
            printf("Index not found\n");
        }
    }
    d=temp1->link;
    temp1->link=temp1->link->link;
    free(d);
    Print();
}
//Searching a linked list
void search(int d,int n)
{
    int i;
    struct node *temp1=head;
    while(temp1!=NULL)
    {
        if(temp1->data==d)
            printf("Element has been found");
        return;
        temp1=temp1->link;
    }
}

//START OF MAIN FUNCTION
int main()
{
    //Main function will take the data, create nodes and add it to the linked list
    int num,i,info,index;
    char choice;
    printf("Enter the number of things you want to enter\n");
    scanf("%d",&num);
    //Ask the user whether they want to enter from the beginning or the end
    printf("Enter the how you would like to enter the data\n");
    printf("Press e if you want it from the end \tPress b if you want it from the beginning \n");
    scanf(" %c",&choice);

    //Choice for end
    if(choice=='e')
    {

    for(i=0;i<num;i++)
    {
        printf("Enter the data you want to enter\n");
        scanf(" %d",&info);
        //To create node and add data
        struct node *temp=(struct node*)malloc(sizeof(struct node));
         temp->data=info;
         if(head==NULL)
         {
             head=temp;
             temp->link=NULL;//IMPORTANT MADE MISTAKE HERE
             continue;

         }
         //To update the link
        struct node *temp1=head;
        while(temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        temp1->link=temp;
        temp->link=NULL;
    }
    }
    //choice for beginning
    else if(choice=='b')
    {
        for(i=0;i<num;i++)
        {
            printf("Enter the data you want to enter\n");
            scanf(" %d",&info);
            add_begin(info);
        }
        Print();

    }
    else
        {
        printf("Invalid choice");
    }
    char c;
    printf("\n");
    //Now for the operations on the Linked list
    printf("Now enter the operation you want to do\n");
    printf("\n");
    printf("Press r to reverse the linked list\n");
    printf("Press i to insert an element at a specific spot in the linked list\n");
    printf("Press d to delete an element in the linked list\n");
    printf("Press p to print the linked list\n");
     printf("Press s to search for an element in the linked list\n");
    scanf("%c",&choice);//To get rid of the newline char from the buffer(Important)
    scanf(" %c",&c);
    printf("Choice is %c",choice);
    if(c=='p')
    {
         Print();
    }
    //To insert an element at a particular position
    else if(c=='i')
    {
        printf("Enter the index you want the new node in\n");
        scanf("%d",&index);
        printf("Enter the data you want to enter\n");
        scanf("%d",&info);
        insert(index,info,num);

    }
    else if(c=='d') 
    {
        printf("Enter the index you want to delete\n");
        scanf("%d",&index);
        del(index,num);

    }
    else if(c=='s')
    {
        printf("Enter the element you want to find \n");
        scanf("%d",&info);
        search(info,num);

    }
    else
    {
            printf("Invalid");
    }
    return 0;
}
