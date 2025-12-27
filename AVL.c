#include<stdio.h>
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

struct node* minValueNode(struct node* root) {
    struct node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node* deletenode(struct node* root, int value) {

    if (root == NULL)
        return root;

    /* STEP 1: BST DELETE */
    if (value < root->key)
        root->left = deletenode(root->left, value);
    else if (value > root->key)
        root->right = deletenode(root->right, value);
    else {
        // node with one or no child
        if (root->left == NULL || root->right == NULL) {
            struct node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            // node with two children
            struct node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    /* STEP 2: UPDATE HEIGHT */
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    /* STEP 3: BALANCE */
    int bf = getbalancefactor(root);

    // LL Case
    if (bf > 1 && getbalancefactor(root->left) >= 0)
        return rightrotate(root);

    // LR Case
    if (bf > 1 && getbalancefactor(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // RR Case
    if (bf < -1 && getbalancefactor(root->right) <= 0)
        return leftrotate(root);

    // RL Case
    if (bf < -1 && getbalancefactor(root->right) > 0) {
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
    int n, value, del;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertnode(root, value);
    }

    printf("\nInorder Traversal before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &del);
    root = deletenode(root, del);

    printf("\nInorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
