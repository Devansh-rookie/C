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
        printf("Give value to the left of %d (-1 to exit):", p->val);
        scanf("%d", &val);
        if(val!=-1){
            node * t = (node *)malloc(sizeof(node));
            enqueue(t);
            t->val = val;
            p->left = t;
            t->left = NULL; t->right = NULL;
        }
        printf("Give value to the right of %d (-1 to exit):", p->val);
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



void mirror(node *tree){
    if(tree== NULL) return;
    mirror(tree->left);
    mirror(tree->right);
    node * temp = tree->right;
    tree->right= tree->left;
    tree->left = temp;
}

int main(){
    // 8 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    create();

    printf("\n");
    levelOrderTraversalProperMethod(root);
    printf("\n");

    mirror(root);
    
    printf("\n");
    levelOrderTraversalProperMethod(root);
    printf("\n");
    return 0;
}
