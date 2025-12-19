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

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->x)
        root->left = deleteNode(root->left, key);

    else if (key > root->x)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1 & 2: node with 0 or 1 child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: node with 2 children
        struct node* temp = minValueNode(root->right);
        root->x = temp->x;
        root->right = deleteNode(root->right, temp->data);
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