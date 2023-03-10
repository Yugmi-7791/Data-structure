// Program to impliment binary search tree.

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node*left;
    struct node*right;
};

//Creating node
struct node * createnode(int data)
{
    struct node * n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

//Inorder taversal
void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

//to check if tree is binary search tree or not
int isbst(struct node*root)
{
    static struct node*prev =NULL;
    if(root!=NULL)
    {
        if(!isbst(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data)
         {
            return 0;
        }
        prev=root;
        return isbst(root->right);
    }
    else{
        return 1;
    }
}

int main()
{
    struct node *p=createnode(6);
    struct node *p1=createnode(4);
    struct node *p2=createnode(7);
    struct node *p3=createnode(1);
    struct node *p4=createnode(5);

 
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p);
    printf("\n");
    printf("%d",isbst(p));//printing elements of tree
    printf("\n");
    return 0;
}
