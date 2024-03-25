#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}Node;


Node * buildTree(Node ** root){

    int val;

    printf("Enter the data:\n");
    scanf("%d", &val);
    *root = (Node *)malloc(sizeof(Node));
    (*root)->val = val;
    (*root)->left= NULL;(*root) ->right = NULL;

    if(val== -1){
        return NULL;
    }

    printf("For Left:\n");
    (*root)->left = buildTree(&(*root)->left);

    printf("For Right:\n");
    (*root)->right = buildTree(&(*root)->right);
    
    return *(root);
}

void levelOrderTraversal(Node * givenNode){
    if(givenNode==NULL){
        return;
    }
    printf("%d ",givenNode->val);

    if(givenNode->left==NULL){
        printf("NULL ");
    }
    if(givenNode->right==NULL){
        printf("NULL ");
    }
    printf("\n");
    levelOrderTraversal(givenNode->left);

    levelOrderTraversal(givenNode->right);
}

int main(){
    Node* root = NULL;

    buildTree(&root);
    printf("\n\n");

    levelOrderTraversal(root);
    return 0;
}
