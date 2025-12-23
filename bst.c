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

struct node* deletenode(struct node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->x)
        root->left = deletenode(root->left, key);

    else if (key > root->x)
        root->right = deletenode(root->right, key);

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
        root->right = deletenode(root->right, temp->x);
    }

    return root;
}

struct node* searchBST(struct node* root, int key) 
{
    while (root != NULL) {
        if (key == root->x)
            return root;
        else if (key < root->x)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main() {
    struct node* root = NULL;
    int n, value,key;

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

    printf("Enter element to search: ");
    scanf("%d", &key);
    struct node* result = searchBST(root, key);
    if (result != NULL)
        printf("Element %d found in BST\n", key);
    else
        printf("Element %d NOT found in BST\n", key);

    printf("Enter element to delete: ");
    scanf("%d", &key);
    root=deletenode(root,key);
    inorder(root);
    printf("\n");
    return 0;
}