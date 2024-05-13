#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

#define maxSize 100

typedef struct node
{
    int val;
    struct node *left;
    struct node * right;
}node;

node * q[maxSize];
int front = -1;
int rear = -1;

int max(int a, int b){
    if(a>b) return a;
    return b;
}

bool isEmpty(){
    if(rear == -1 || front == -1) return true;
    return false;
}

void enqueue(node * n){
    if(isEmpty()){
        front = rear =0;
        q[rear] = n;
        return;
    }
    rear++;
    q[rear] = n;
}

node * dequeue(){
    if(isEmpty()){
        return NULL;
    }
    node * x= q[front];
    // front++;
    for(int i=front;i<rear;i++){
        q[i] = q[i+1];
    }
    rear--;
    return x;
}

node * createBT(){
    int val;
    node * root = (node *)malloc(sizeof(node));
    printf("Value of Root: ");
    scanf("%d",&val);
    enqueue(root);
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    node *p;
    while (!isEmpty())
    {
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
    return root;
}

void levelOrderTraversalGood(node * root){
    if(root== NULL) return;
    enqueue(root);
    enqueue(NULL);// add it at the end of each line and then add a newline character
    while(!isEmpty()){
        node * p = dequeue();
        if(p==NULL){// adding at the ending of the line
            printf("\n");
            if(!isEmpty()) enqueue(NULL);
        }
        else{
            printf("%d ", p->val);
            if(p->left) enqueue(p->left);
            if(p->right) enqueue(p->right);
        }
    }
}

void levelOrderNormal(node * root){
    if(root== NULL) return;
    enqueue(root);
    while(!isEmpty()){
        node * p = dequeue();
        printf("%d ", p->val);
        if(p->left) enqueue(p->left);
        if(p->right)enqueue(p->right);
    }
}

void preOrderDLR(node * root){
    if(root == NULL) return;
    printf("%d ", root->val);
    preOrderDLR(root->left);
    preOrderDLR(root->right);
}

void postOrderLRD(node * root){
    if(root== NULL) return;
    postOrderLRD(root->left);
    postOrderLRD(root->right);
    printf("%d ", root->val);
}

void inOrderLDR(node * root){
    if(root==NULL) return;
    inOrderLDR(root->left);
    printf("%d ", root->val);
    inOrderLDR(root->right);
}

int height(node * root){
    if(root==NULL) return 0;
    int hLeft = height(root->left);
    int hRight = height(root->right);
    return max(hLeft, hRight)+1; // increase one each time as we are going we each time
}

int count_nodes(node * root){
    if(root== NULL) return 0;
    int cLeft= count_nodes(root->left);
    int cRight = count_nodes(root->right);
    return cLeft + cRight + 1;
}

int countNode2Child(node * root){
    if(root == NULL) return 0;
    if(root->left == NULL || root->right==NULL) return 0;
    int cLeft = countNode2Child(root->left);
    int cRight = countNode2Child(root->right);
    if(root->left && root->right){
        return  cLeft+cRight+1;// incremented
    }
    return cLeft + cRight; // not incremented
}

int sumBT(node * root){
    if(root == NULL) return 0;
    int sumLeft = sumBT(root->left);
    int sumRight = sumBT(root->right);
    return root->val +sumLeft+sumRight;
}

void mirrorBT(node * root){
    if(root == NULL){
        return;
    }
    mirrorBT(root->left);
    mirrorBT(root->right);
    node * temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    // 8 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    node * root = createBT();

    printf("\n");
    preOrderDLR(root);
    printf("\n");

    printf("\n");
    postOrderLRD(root);
    printf("\n");

    printf("\n");
    inOrderLDR(root);
    printf("\n");

    printf("\n");
    levelOrderNormal(root);
    printf("\n");

    printf("\n");
    levelOrderTraversalGood(root);
    printf("\n");

    printf("\n");
    printf("Height of the tree is: %d",height(root));
    printf("\n");

    printf("\n");
    printf("Number Nodes of the tree is: %d",count_nodes(root));
    printf("\n");

    printf("\n");
    printf("Number of 2 Child Nodes of the tree is: %d",countNode2Child(root));
    printf("\n");

    printf("\n");
    printf("Sum of the nodes of the tree is: %d",sumBT(root));
    printf("\n");

    mirrorBT(root);

    printf("\n");
    levelOrderTraversalGood(root);
    printf("\n");

    return 0;
}
