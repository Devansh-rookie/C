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

node * rSearch(node *tree, int val){
    if(tree== NULL) return NULL;
    else if(tree->val == val) return tree;
    else if(tree->val > val) rSearch(tree->left, val);
    else rSearch(tree->right, val);
    return NULL;
}

node * search(node *tree, int val){
    while(tree!=NULL){
        if(tree->val == val) return tree;
        else if(tree->val > val) tree=tree->left;
        else tree =(tree->right);
    }
    return NULL;
}

void insert(node * tree, int val){
    node * treeTail;
    while(tree!=NULL){
        treeTail= tree;
        if(val == tree->val){
            return;// as the 
        }
        else if(val<tree->val){
            tree =tree->left;
        }
        else{
            tree= tree->right;
        }
    }
    node * p = (node*)malloc(sizeof(node));
    p->val = val;
    p->left = NULL ; p->right = NULL;
    if(p->val>treeTail->val) treeTail->right = p;
    else treeTail->left = p;
}

node * createNode(int val){
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    t->left = NULL; t->right = NULL;
    return t;
}

node * rInsert(node * tree, int key){
    if(tree == NULL) root = createNode(key);
    else if(tree->val>=key) tree->left = rInsert(tree->left, key);
    else tree->right = rInsert(tree->right, key);
    return root;
}



int main(){

    return 0;
}
