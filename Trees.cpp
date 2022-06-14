#include<iostream>
using namespace std;
#include<queue>
// Must add deletion function
struct bstnode
{
    int data;
    bstnode *left;
    bstnode *right;
};

void level_order(bstnode* root)
{
    queue<bstnode*> q;
    
    if(root==NULL)
    {
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        bstnode* top=q.front();
       
        if(top->left!=NULL)
    {
        q.push(top->left);
    }
     if(top->right!=NULL)
    {
        q.push(top->right);
    }
        cout<<" "<<top->data;
        q.pop();
    }
}

void preorder(bstnode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(bstnode* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;

}

void inorder(bstnode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
     cout<<" "<<root->data;
    inorder(root->right);


}


//To make the node
bstnode* create_new_node(int data)
{
    bstnode *newnode= new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}


//To insert the node
bstnode* Insert(bstnode *root,int data)
{
    /*
        Basically I check whether the data to be entered is lesser than
        or equal to the data in the root node
    */
    if(root==NULL)
    {
        root=create_new_node(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {

        root->right=Insert(root->right,data);
    }
    return root;
}

int main()
{
    int data,i,num;
    cout<<"Enter number of nodes you want \n";
    cin>>num;
    bstnode *root=NULL;
    for(i=0;i<num;i++)
    {
         cout<<"Enter the data\n";
        cin>>data;
        root=Insert(root,data);

    }
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    cout<<"Level\n";
   level_order(root);

    return 0;
}
