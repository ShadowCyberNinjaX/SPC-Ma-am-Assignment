#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct node {
    int key;
    enum Color color;
    struct node *left, *right, *parent;
};

// Create a new node
struct node* createNode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->color = RED;  // new nodes are always red initially
    newnode->left = newnode->right = newnode->parent = NULL;
    return newnode;
}

// Left rotate
struct node* leftRotate(struct node* root, struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    return root;
}

// Right rotate
struct node* rightRotate(struct node* root, struct node* y) {
    struct node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;

    return root;
}

struct node* BSTInsert(struct node* root, struct node* pt) {
    if (root == NULL)
        return pt;

    if (pt->key < root->key) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->key > root->key) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

// Insert wrapper for RBT
struct node* insert(struct node* root, int key) {
    struct node* pt = createNode(key);
    root = BSTInsert(root, pt);
    root = fixViolation(root, pt);
    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d(%s) ", root->key, root->color == RED ? "R" : "B");
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    int n, val;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal with Colors:\n");
    inorder(root);
    printf("\n");

    return 0;
}

