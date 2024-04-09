#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
}node;

node * createNode(int val){
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

node * insertValue(node * root, int val){
    if(root == NULL) root = createNode(val);
    else if(root->val>= val) 
        root->left =insertValue(root->left, val);
    else 
        root->right = insertValue(root->right, val);
    return root;
}



int main(){
    node * root = NULL;
    char ch;
    while(true){
        printf("What is the value to insert(q to exit): "); 
        scanf("%c", &ch);
        if(ch == 'q') break;
        root = (insertValue(root ,(int)ch));
    }
    return 0; 
}
