#include <stdio.h>
#include <stdlib.h>

struct node *newNode(int);
struct node *insertNewNode(struct node*, int);
struct node *deleteNode(struct node*, int);
void inorder(struct node*);

struct node {
    int data;
    struct node *left, *right;
};

int main() {
    struct node *root = NULL;
    while(1){
        printf("==========================================\n");
        printf("please select your options\n");
        printf("select 1 to insert new node\n");
        printf("select 2 to delete a node\n");
        printf("select 3 to print the tree\n");
        int choice;
        scanf("%d", &choice);
        int data;
        switch(choice){
            case 1: printf("enter the data you want to insert: ");
                    scanf("%d", &data);
                    root = insertNewNode(root, data);
                    break;
            case 2: printf("enter the data you want to delete: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                    break;
            case 3: inorder(root);
                    printf("\n");
                    break;
            default: exit(0);
        }
    }
}

struct node *newNode(int key){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insertNewNode(struct node* root, int key){
    if(root==NULL) return newNode(key);
    if(key < root->data){
        root->left = insertNewNode(root->left, key);
    } else {
        root->right = insertNewNode(root->right, key);
    }
    return root;
}

struct node *deleteNode(struct node *root, int key){
    if(root==NULL) return root;
    struct node *cur = root, *parent = NULL, *q, *succ;
    while (cur!=NULL) {
        if(cur->data == key) break;
        parent = cur;
        if(key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    if(cur==NULL) {
        printf("item not found\n");
        return root;
    }
    if(cur->left == NULL) q = cur->right;
    else if (cur->right == NULL) q = cur->left;
    else {
        q = cur->right;
        succ = cur->right;
        while (succ->left!=NULL) {
            succ = succ->left;
        }
        succ->left = cur->left;
    }
    if(parent==NULL) return q;
    if(q->data < parent->data){
        parent->left = q;
    } else {
        parent->right = q;
    }
    free(cur);
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}
