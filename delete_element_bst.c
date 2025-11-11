#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *left, *right;
};

struct node* createnode(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->x=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insertnode(struct node* root, int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    if(value<root->x)
    {
        root->left=insertnode(root->left,value);
    }
    else
    {
        root->right=insertnode(root->right,value);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->x);
        inorder(root->right);
    }
}

struct node* inorderpre(struct node* root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node* deletenode(struct node* root, int value)
{
    struct node* pre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(value<root->x)
        root->left=deletenode(root->left,value);
    else if(value>root->x)
        root->right=deletenode(root->right,value);
    else{
        pre=inorderpre(root);
        root->x=pre->x;
        root->left=deletenode(root->left,pre->x);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertnode(root, value);
    }

    printf("\nInorder Travarsal : ");
    inorder(root);
    printf("\n");
    deletenode(root,5);
    inorder(root);
    printf("\n");
    return 0;
}