
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
} node;

node * root = NULL;

node * createNode(int val) {
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

node * insert(node * root, int val) {
    if (root == NULL)
        root = createNode(val);
    else if (val <= root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void DLR(node * tree) {
    if (tree == NULL)
        return;
    printf("%d ", tree->val);
    DLR(tree->left);
    DLR(tree->right);
}

void LDR(node * tree) {
    if (tree == NULL)
        return;
    LDR(tree->left);
    printf("%d ", tree->val);
    LDR(tree->right);
}

void LRD(node * tree) {
    if (tree == NULL)
        return;
    LRD(tree->left);
    LRD(tree->right);
    printf("%d ", tree->val);
}

int main() {
    int n;
    printf("What are number of values:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int s;
        scanf("%d",&s);
        root = insert(root, s);
    }
    printf("\nPreorder /DLR Traversal:\n");
    DLR(root);
    printf("\n");

    printf("\nInorder /LDR Traversal:\n");
    LDR(root);
    printf("\n");

    printf("\nPostOrder /LRD Traversal:\n");
    LRD(root);
    printf("\n");

    return 0;
}
