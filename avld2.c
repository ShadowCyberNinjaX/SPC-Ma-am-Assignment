int getheight(Node *root){
        if(!root) return 0;
        return root->height;
    }
    int getbalance(Node *root){
        if(!root){
            return 0;
        }
        return getheight(root->left) - getheight(root->right);
    }
    Node *leftRotation(Node *root){
        
        Node *child = root->right;
        Node *childLeft = child->left;
        child->left = root;
        root->right = childLeft;
        
        root->height = 1 + max(getheight(root->left),getheight(root->right));
        child->height = 1 + max(getheight(child->left),getheight(child->right));
        
        return child;
    }
    Node *rightRotation(Node *root){
        Node *child = root->left;
        Node *childRight = child->right;
        child->right = root;
        root->left = childRight;
        
        root->height = 1 + max(getheight(root->left),getheight(root->right));
        child->height = 1 + max(getheight(child->left),getheight(child->right));
        
        return child;
    }
Node* deleteNode(Node* root, int data)
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
            delete root;
            return NULL;
        }
        else if(!root->left && root->right){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left && !root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // both child exist
        else{
            Node *curr = root->right;
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
