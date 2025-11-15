#include<stdio.h> //need for check up
#include<stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getheight(struct node* root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getbalancefactor(struct node* root) {
    if (root == NULL)
        return 0;
    return getheight(root->left) - getheight(root->right);
}

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

struct node* rightrotate(struct node* y) {
    struct node* x = y->left;
    struct node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(getheight(y->left), getheight(y->right));
    x->height = 1 + max(getheight(x->left), getheight(x->right));

    return x;
}

struct node* leftrotate(struct node* x) {
    struct node* y = x->right;
    struct node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}

struct node* insertnode(struct node* root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->key)
        root->left = insertnode(root->left, value);
    else if (value > root->key)
        root->right = insertnode(root->right, value);
    else
        return root; // duplicate not allowed

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = getbalancefactor(root);

    // LL Case
    if (bf > 1 && value < root->left->key)
        return rightrotate(root);

    // RR Case
    if (bf < -1 && value > root->right->key)
        return leftrotate(root);

    
    // LR Case
    if (bf > 1 && value > root->left->key) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // RL Case
    if (bf < -1 && value < root->right->key) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
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

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
