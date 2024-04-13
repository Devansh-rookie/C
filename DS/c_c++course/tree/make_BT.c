#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define maxSize 100

typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
}node;

node * q[maxSize];
int front =-1, rear = -1;
node * root;

bool isEmpty(){
    if(front == -1 || rear == -1){
        return true;
    }
    return false;
}

void enqueue(node * value){
    if(isEmpty()){
        front = 0;rear = 0;
    }
    else rear++;
    q[rear] = value;
}

node * dequeue(){// if there is only one element do front = -1 and rear = -1
    if(isEmpty()) return NULL;
    node * t = q[front];
    for(int i=front;i<=rear;i++){
        q[i]=q[i+1];
    }
    rear--;
    return t;
}

int max(int a, int b){
    if(a>b)return a;
    return b;
}

void create(){
    node * p, t;
    int val;
    printf("Give value for root: ");
    scanf("%d",&val);
    root = (node *)malloc(sizeof(node));
    root->val = val;
    enqueue(root);
    while(!isEmpty()){
        p = dequeue();
        printf("Give value to the left of %d :", p->val);
        scanf("%d", &val);
        if(val!=-1){
            node * t = (node *)malloc(sizeof(node));
            enqueue(t);
            t->val = val;
            p->left = t;
            t->left = NULL; t->right = NULL;
        }
        printf("Give value to the right of %d :", p->val);
        scanf("%d", &val);
        if(val!=-1){
            node * t = (node *)malloc(sizeof(node));
            enqueue(t);
            t->val = val;
            p->right = t;
            t->left = NULL; t->right = NULL;
        }
    }
}

void preorder_DLR(node * root_print){
    if(root_print == NULL) return;
    printf("%d ", root_print->val);
    preorder_DLR(root_print->left);
    preorder_DLR(root_print->right);
}

void postOrderLRD(node * root_print){
    if(root_print== NULL) return;
    postOrderLRD(root_print->left);
    postOrderLRD(root_print->right);
    printf("%d ", root_print->val);
}

void inOrderLDR(node * root_print){
    if(root_print==NULL) return;
    inOrderLDR(root_print->left);
    printf("%d ", root_print->val);
    inOrderLDR(root_print->right);
}

void levelOrderTraversal(node * localRoot){
    enqueue(localRoot);
    while(!isEmpty()){
        node * p = dequeue();
        printf("%d ",p->val);
        if(p->left){
            enqueue(p->left);
        }
        if(p->right){
            enqueue(p->right);
        }
    }
}

void levelOrderTraversalProperMethod(node * localRoot){
    enqueue(localRoot);
    enqueue(NULL);
    while(!isEmpty()){
        node * p = dequeue();
        if(p==NULL){
            printf("\n");
            if(!isEmpty()) enqueue(NULL);
        }
        else{
            printf("%d ",p->val);
            if(p->left){
                enqueue(p->left);
            }
            if(p->right){
                enqueue(p->right);
            }
        }
    }
}

void levelOrderTraversalProperMethodwith0s(node * localRoot){
    enqueue(localRoot);
    enqueue(NULL);
    node * forEmpty = (node*)malloc(sizeof(node));
    // forEmpty->val = 0;
    while(!isEmpty()){
        node * p = dequeue();
        if(p==NULL){
            printf("\n");
            if(!isEmpty()) enqueue(NULL);
        }
        else if(p==forEmpty){
            printf("-1 ");
        }
        else{
            printf("%d ",p->val);
            if(p->left){
                enqueue(p->left);
            }
            else if(p->left==NULL) enqueue(forEmpty);
            if(p->right){
                enqueue(p->right);
            }
            else if(p->right==NULL) enqueue(forEmpty);
        }
    }
}

int height(node * tree){
    if(tree==NULL) return 0;
    int hLeft, hRight;
    hLeft = height(tree->left);
    hRight = height(tree->right);
    return max(hLeft,hRight)+1;
}

int count(node * tree){
    if(tree==NULL) return 0;
    int countLeft, countRight;
    countLeft = count(tree->left);
    countRight = count(tree->right);
    return countLeft+countRight+1;// if we are doing +1 it means that we are counting that node else we are not
}

int count_nodes_with_2_child(node * tree){
    if(tree == NULL)return 0;
    int cLeft, cRight;
    cLeft = count_nodes_with_2_child(tree->left);
    cRight = count_nodes_with_2_child(tree->right);
    if(tree->left && tree->right){
        return cLeft+cRight+1;// +1 means we are counting that node and if that particular node has both childs
    }
    return cLeft+cRight;// else if the node doesn't have both nodes it would give +0 so it didn't count
}

int sum_bt(node * tree){
    if(tree == NULL) return 0;
    int sumLeft , sumRight;
    sumLeft = sum_bt(tree->left);
    sumRight = sum_bt(tree->right);
    return sumLeft+ sumRight + tree->val;// tree val for summation of each node.
}

int main(){
    // 8 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    create();

    printf("\n");
    preorder_DLR(root);
    printf("\n");

    printf("\n");
    inOrderLDR(root);
    printf("\n");

    printf("\n");
    postOrderLRD(root);
    printf("\n");

    printf("\n");
    levelOrderTraversal(root);
    printf("\n");

    printf("\n");
    levelOrderTraversalProperMethod(root);
    printf("\n");

    printf("\n");
    levelOrderTraversalProperMethodwith0s(root);
    printf("\n");

    printf("\n Height is: %d\n",height(root));
    printf("\n Number of Nodes is: %d\n",count(root));
    return 0;
}
