#include<stdio.h>//need for modifications
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getheight(struct Node *root){
    if(!root) return 0;
        return root->height;
}

int getbalance(struct Node *root){
    if(!root){
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

struct Node *leftRotation(struct Node *root){
        
    struct Node *child = root->right;
    struct Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
        
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
        
    return child;
}

struct Node *rightRotation(struct Node *root){
    struct Node *child = root->left;
    struct Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
        
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
        
    return child;
}

struct Node* deleteNode(struct Node* root, int data)
{
    //add code here,
    if(!root) return NULL;
    
    if(data < root->data){
        root->left = deleteNode(root->left,data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right,data);
    }
    else{
        //Leaf Node
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
        else if(!root->left && root->right){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left && !root->right){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // both child exist
        else{
            struct Node *curr = root->right;
            while(curr->left){
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right,curr->data);
            
        }
    }
    
    
    // update heioght
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    // check balancing
    
    int balance = getbalance(root);
    if(balance > 1){
        //LL
        if(getbalance(root->left) >= 0){
            return rightRotation(root);
        }else{
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }else if(balance < -1){
        //RR
        if(getbalance(root->right) <= 0){
            return leftRotation(root);
        }
        //RL
        else{
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}

struct Node* insertnode(struct Node* root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insertnode(root->left, value);
    else if (value > root->data)
        root->right = insertnode(root->right, value);
    else
        return root; // duplicate not allowed

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = getbalancefactor(root);

    // LL Case
    if (bf > 1 && value < root->left->data)
        return rightrotate(root);

    // RR Case
    if (bf < -1 && value > root->right->data)
        return leftrotate(root);

    // LR Case
    if (bf > 1 && value > root->left->data) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // RL Case
    if (bf < -1 && value < root->right->data) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
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
