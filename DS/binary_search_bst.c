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

int arr[maxSize];
int i=0;

void inOrderLDR(node * root_print){
    if(root_print==NULL) return;
    inOrderLDR(root_print->left);
    printf("%d ", root_print->val);
    // enqueue(root_print->val);
    arr[i++]= root_print->val;
    inOrderLDR(root_print->right);
}


bool checkSorted(){
    int j=0;
    while(j<i-1){
        if(arr[j]>arr[j+1]){
            return false;
        }
        // printf("%d ", arr[j]);
        j++;
    }
    return true;
}

int main(){

    create();

    printf("\n");
    inOrderLDR(root);
    printf("\n");

    if(checkSorted()){
        printf("The given Binary Tree is a BST");
    }
    else printf("The given Binary Tree is not a BST");

    return 0;
}
