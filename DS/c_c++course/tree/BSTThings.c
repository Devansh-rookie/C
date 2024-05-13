#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

#define maxSize 100

//for adding duplicate nodes in the BST for each node



typedef struct node
{
    int val;
    struct node *left;
    struct node * right;
}node;

node * q[maxSize];
int front = -1;
int rear = -1;

node * arr[100];
int i=0;

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

node * createNode(int val){
    node * t =(node*)malloc(sizeof(node));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

node * insert(node * root,int val){
    if(root == NULL){
        root = createNode(val);
    }
    else if(root->val>= val) root->left = insert(root->left, val);
    else if(root->val< val) root->right = insert(root->right, val);
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

node * recursiveSearch(node * root, int val){
    if(root == NULL) return NULL;
    if(root->val == val) return root;
    else if(root->val>val) recursiveSearch(root->left,val);
    else if(root->val<val) recursiveSearch(root->right,val);
    return NULL;
}

node * deleteNode(node * root, int key){
    if(root == NULL) return root;

    if(root->val>key){
        root->left = deleteNode(root->left,key);
        return root;
    }
    else if(root->val<key){
        root->right = deleteNode(root->right, key);
        return root;
    }
    // Case 1 and Case 2
    if(root->left == NULL){
        node * temp = root->right;
        free(root);

        return temp;
    }
    if(root->right == NULL){
        node * temp = root->left;
        free(root);

        return temp;
    }

    // Case 3
    node * successorParent = root;// current selected value who's value we have to change, since we have already used the values like root->left and root->right = function so it will automatically reassign everything that is needed.
    node * successor = root->right;// right subtree's smallest value is the inOrder Successor and the left subtree's largest value is the InOrder predecessor
    while(successor->left !=NULL){
        successorParent = successor;
        successor= successor->left;
    }

    root->val = successor->val;

    if(successorParent ->left == successor){// if the successor is down the tree instead of being directly to the right of the root
        successorParent->left = successor->right;// as successor->left == NULL;
    }
    else{// in this case the successor if directly to the right so the right value is to be shifted instead of the left one.
        successorParent->right = successor->right;
    }
    return root; // return the new root;
}


void addNodesToArr(node * root){
    if(root == NULL){
        return;
    }
    // According to Preorder
    arr[i++] = root;
    addNodesToArr(root->left);
    addNodesToArr(root->right);
}



void makeNew(node * root){
    if(root==NULL) return;
    node *t = (node*)malloc(sizeof(node));
    t->right = NULL;
    t->val = root->val;
    t->left = root->left;
    root->left = t;
}


void addDuplicates(node * root){
    for(int j=0;j<=i;j++){
        makeNew(arr[j]);
    }
}


int main(){
    // 50 30 70 20 40 60 80 -1
    node * root= NULL;
    int ch;
    while(true){
        scanf("%d", &ch);
        if(ch==-1) break;
        root = insert(root,ch);
    }

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

    deleteNode(root, 50);

    printf("\n");
    levelOrderTraversalGood(root);
    printf("\n");

    printf("\n");
    preOrderDLR(root);
    printf("\n");

    addNodesToArr(root);
    addDuplicates(root);

    printf("\n");
    preOrderDLR(root);
    printf("\n");

    printf("\n");
    levelOrderTraversalGood(root);
    printf("\n");

    return 0;
}
