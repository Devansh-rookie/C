#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define maxsize 10

int queue[maxsize];
int rear = -1, front= -1;

int stk[maxsize];


int top = -1;

bool is_empty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool is_full(){
    if(top == maxsize-1) return true;
    return false;
}

void push(int x){// if we use structure here we can use any stricture with this function.
    if(!is_full()) stk[++top]= x;
    // here ++stk means pre increment that means that first we increment the number then we assign the value so it also changes top and it also assigns x to the stk value.
    else printf("The stack is full");
}

int pop(){
    if(!is_empty()){
        int v = stk[top];
        top--;
        return v;
    }
    else printf("The stack is empty");
}


bool isFull(){
    if(rear== maxsize-1) return true;
    return false;
}

bool isEmpty(){
    if(rear == -1 || front == -1) return true;
    return false;
}

void enqueue(int x){
    if(isFull()){
        printf("Overflow");
        return;
    }
    else if(isEmpty()) rear=0,front =0;// for empty condition directly add to rear
    else rear++; // for normal conditions
    queue[rear]=x;
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }
    else if(rear == 0){
        rear--;
        return;
    }
    for(int i=front;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear--;
}

void front_disp(){
    if(!isEmpty()) printf("%d",queue[front]);
    else printf("Underflow");
}

void display(){
    if(!isEmpty()){
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

// void reverse(int k){
//     if(k>0){
//         push(queue[front]);
//         dequeue();
//         reverse(k-1);
//     }
// }

// void reverse_queue(int k){
//     if(k>0){
//         enqueue(pop());
//         reverse_queue(k-1);
//     }
// }

void reverse_new(int k){
    if(k>0){
        int x= queue[front];
        dequeue();
        reverse_new(k-1);
        enqueue(x);
    }
}

void switch_case(){
    int ch;
    while (true)
    {
        printf("\n");
        printf("Give your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Reverse K Elements\n0. Exit\n");
        scanf("%d",&ch);
        int k;
        switch (ch)
        {
        case 1:
            printf("What to Enqueue: ");
            int a;
            scanf("%d",&a);
            enqueue(a);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            front_disp();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("K: ");
            scanf("%d",&k);
            // reverse(k);
            // reverse_queue(k);
            reverse_new(k);
            break;
        case 0:
            return;
            break;
        default:
            printf("Enter a valid value\n");
            break;
        }
    }
}

int main(){
    switch_case();

    return 0;
}
