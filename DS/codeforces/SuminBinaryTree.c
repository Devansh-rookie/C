#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>


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

node * createBT(node * root, int n){
    int c_val=1;
    (root) = (node *)malloc(sizeof(node));
    (root)->val = c_val;
    queueNode * first = NULL; queueNode * last = NULL;
    enqueue(&first, &last, root);
    node *p=NULL;
    while (!isEmpty(first)&& c_val<=n)
    {
        c_val++;
        p = dequeue(&first)->val;
        node * t = (node *)malloc(sizeof(node));
        t->val = c_val;
        p->left = t;
        t->left = NULL; t->right = NULL;
        enqueue(&first, &last, t);
        
        c_val++;
        node * t2 = (node *)malloc(sizeof(node));
        t2->val = c_val;
        p->right = t2;
        t2->left = NULL; t2->right = NULL;
        enqueue(&first, &last, t2);
        
    }
    while (!isEmpty(first))
    {
        dequeue(&first);
    }
    
    return root;
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

int sumBT(node * tree, int key, int sum){
    if(tree == NULL){
        sum=0;
        return 0;
    }
    if(tree->val== key) return key;
    
}

int main()
{
    node * root = createBT(root, 16);
    levelOrderTraversal(root);    
    printf("\n%d\n", sumBT(root, 4,0));
    return 0;
}