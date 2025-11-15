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

// Fix Red-Black Tree properties after insertion
struct node* fixViolation(struct node* root, struct node* pt) {
    struct node* parent_pt = NULL;
    struct node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color == RED) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = parent_pt->parent;

        // Parent is left child of grandparent
        if (parent_pt == grand_parent_pt->left) {
            struct node* uncle_pt = grand_parent_pt->right;

            // Case 1: Uncle is RED → recolor
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else {
                // Case 2: pt is right child → left rotate
                if (pt == parent_pt->right) {
                    root = leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case 3: pt is left child → right rotate
                root = rightRotate(root, grand_parent_pt);
                enum Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }

        // Parent is right child of grandparent
        else {
            struct node* uncle_pt = grand_parent_pt->left;

            // Case 1: Uncle is RED → recolor
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else {
                // Case 2: pt is left child → right rotate
                if (pt == parent_pt->left) {
                    root = rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                // Case 3: pt is right child → left rotate
                root = leftRotate(root, grand_parent_pt);
                enum Color temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
    return root;
}

// Insert a node into BST (standard insert)
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

