#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int val){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val>root->data){
        insert(root->right,val);
    }else if(val<root->data){
        insert(root->left,val);
    }else{
        printf("invalid number");
        return NULL;
    }
    return root;
}

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d",root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        preOrder(root->left);
        printf("%d",root->data);
        preOrder(root->right);
    }
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


int isBST(struct node* root){
    if(root==NULL){
        return 1;
    }
    if(root->left!=NULL && root->left->data > root->data){
        return 0;
    }
    if(root->right!=NULL && root->right->data < root->data){
        return 0;
    }
    if(!isBST(root->left) || !isBST(root->right)){
        return 0;
    }
    return 1;
}

struct node* searchBST(struct node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        return root;
    }
    if(val>root->data){
        searchBST(root->right,val);
    }else{
        searchBST(root->left,val);
    }
}



struct node* findMin(struct node* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL){
        return root;
    }
    findMin(root->left);
}

struct node* findMax(struct node* root){
    if(root==NULL){
        return NULL;
    }
    if(root->right==NULL){
        return root;
    }
    findMin(root->right);
}

struct node* searchBSTtype2(struct node* root, int val) {
    if (root!= NULL) {
    
        if (root->data == val) {
            return root;
        }
        
        if (val > root->data) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
        return NULL;
    }
}

int main(){
    return 0;
}