#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxSize 100
typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
}node;


void enqueue(node * queue[], int *front, int *end, node * value){
    if(*front == -1 || *end == -1){
        *front = 0; *end = 0;
    }
    else if(*end == maxSize -1) printf("The queue is full.");
    else (*end)= (*end)+1;
    queue[*end] = value;
    return;
}

void dequeue(node * queue[], int *front, int *end){
    for(int i= *front;i< *end-1;i++){
        queue[i]=queue[i+1];
    }
    *end = *end -1;
    return;
}

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

void levelOrderTraversal(node * root){
    static node * q[maxSize];
    static int front = -1;
    static int end = -1;
    enqueue(q,&front, &end, root);
    // enqueue(q, &front, &end, NULL);
    while (end!= -1)
    {
        node * temp = q[front];
        dequeue(q, &front, &end);
        enqueue(q,&front, &end,NULL);
        if(temp == NULL){
            printf("\n");
            if(end!=-1){
                // as now q still has child nodes
                enqueue(q,&front, &end, NULL);
            }
        }
        else{
            printf("%d ", temp->val);
            if(temp->left){
                enqueue(q,&front, &end, temp->left);
            }
            if(temp->right){
                enqueue(q,&front, &end, temp->right);
            }
        }
    }
}

void levelOrderRecursive(node * root){
    if(root==NULL) return;
    
}

int main(){
    node * root = NULL;
    int ch;
    while(true){
        printf("What is the value to insert(q to exit): "); 
        scanf("%d", &ch);
        if(ch == 0) break;
        root = (insertValue(root ,ch));
    }
    levelOrderRecursive(root);
    return 0;
}
