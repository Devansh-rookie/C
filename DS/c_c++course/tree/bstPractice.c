// #include<stdio.h>
// #include<stdio.h>
// #include<stdbool.h>
// #include<stdlib.h>
// #define maxSize 100

// typedef struct node
// {
//     int val;
//     struct node * left;
//     struct node * right;
// }node;

// node * root=NULL;

// typedef struct queueNode
// {
//     node * val;
//     struct node * next;
// }queueNode;

// bool isEmpty(node * first){
//     if(first == NULL){
//         // printf("Underflow\n");
//         return true;
//     }
//     return false;
// }

// node * peek(node * first){
//     if(isEmpty(first)) return NULL;
//     return (first);
// }

// queueNode * dequeue(queueNode ** first){
//     if(isEmpty(*first)) return NULL;
//     node * t = (*first);
//     (*first) = (*first)->next;
//     // free(t);
//     return (t);
// }

// queueNode * insertAtLast(queueNode ** first, queueNode ** last, int val){// enqueue
//     queueNode * t = (queueNode *)malloc(sizeof(queueNode));
//     t->val = val;
//     t->next = NULL;
//     if(isEmpty(*first)){
//         (*first)= t;
//         (*last)= t;
//         return t;
//     }
//     (*last)->next = t;
//     (*last) = t;
//     return (*first);
// }

// node * createNode(int val){
//     node * t = (node *)malloc(sizeof(node));
//     t->val = val;
//     t->left = NULL; t->right= NULL;
//     return t;
// }

// node * insert(node * root, int val){
//     if(root== NULL) root = createNode(val);
//     else if(val<= root->val) root->left = insert(root->left, val);
//     else root->right= insert(root->right, val);
//     return root;
// }

// void DLR(node * tree){
//     if(tree== NULL) return;
//     printf("%d ",tree->val);
//     DLR(tree->left);
//     DLR(tree->right);
// }

// void LDR(node * tree){
//     if(tree== NULL) return;
//     LDR(tree->left);

//     printf("%d ",tree->val);
    
//     LDR(tree->right);
// }

// void LRD(node * tree){
//     if(tree== NULL) return;
//     LRD(tree->left);

//     LRD(tree->right);
    
//     printf("%d ",tree->val);
// }

// void levelOrderTraversal(node * tree, queueNode** first, queueNode** last){
//     insertAtLast(first, last, tree);
//     insertAtLast(first, last, NULL);
//     while(isEmpty(*first)){
//         node * t = dequeue(first);
//         // this could be breaking point
//         if(t==NULL && !isEmpty(*first)){
//             printf("\n");
//             if(isEmpty(*first)) insertAtLast(first, last, NULL);
//         }
//         else{
//             printf("%d ", t->val);
//             if(t->left){
//                 insertAtLast(first,last,t->left);
//             }
//             if(t->right){
//                 insertAtLast(first,last,t->right);
//             }
//         }
//     }
// }


// int main(){

//     queueNode* first=NULL;
//     queueNode* last=NULL;

//     root = insert(root, 8);
//     root = insert(root, 3);
//     root = insert(root, 5);
//     root = insert(root, 4);
//     root = insert(root, 9);
//     root = insert(root, 7);
//     root = insert(root, 2);

//     printf("\n");
//     DLR(root);
//     printf("\n");

//     printf("\n");
//     LDR(root);
//     printf("\n");

//     printf("\n");
//     LRD(root);
//     printf("\n");

//     printf("\n");
//     levelOrderTraversal(root, &first, &last);
//     printf("\n");
//     return 0;
// }
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

typedef struct queueNode
{
    node * val;
    struct queueNode * next;
} queueNode;

bool isEmpty(queueNode * first) {
    return (first == NULL);
}

node * peek(queueNode * first) {
    if (isEmpty(first))
        return NULL;
    return (first->val);
}

queueNode * dequeue(queueNode ** first) {
    if (isEmpty(*first))
        return NULL;
    queueNode * t = *first;
    *first = (*first)->next;
    return t;
}

void enqueue(queueNode ** first, queueNode ** last, node * val) {
    queueNode * t = (queueNode *)malloc(sizeof(queueNode));
    t->val = val;
    t->next = NULL;
    if (isEmpty(*first)) {
        *first = t;
        *last = t;
    } else {
        (*last)->next = t;
        *last = t;
    }
}

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

void levelOrderTraversal(node * tree) {
    if (tree == NULL)
        return;
    queueNode * first = NULL;
    queueNode * last = NULL;
    enqueue(&first, &last, tree);
    enqueue(&first, &last, NULL);
    while (!isEmpty(first)) {
        node * t = dequeue(&first)->val;
        if (t == NULL) {
            printf("\n");
            if (!isEmpty(first))
                enqueue(&first, &last, NULL);
        } else {
            printf("%d ", t->val);
            if (t->left)
                enqueue(&first, &last, t->left);
            if (t->right)
                enqueue(&first, &last, t->right);
        }
    }
}

int main() {
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    printf("\nDLR Traversal:\n");
    DLR(root);
    printf("\n");

    printf("\nLDR Traversal:\n");
    LDR(root);
    printf("\n");

    printf("\nLRD Traversal:\n");
    LRD(root);
    printf("\n");

    printf("\nLevel Order Traversal:\n");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
