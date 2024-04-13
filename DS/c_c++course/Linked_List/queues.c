#include<stdio.h>
#include<stdbool.h>
#define maxSize 100

int queue[maxSize];
int front =-1;
int rear =-1;

bool isEmpty(){
    if(front==-1 || front>rear) return true;
    return false;
}

void dequeue(){
    if(isEmpty()) return;
    else if(front == rear){
        front = rear = -1;
    }
    front++;
}

bool isFull(){
    if(rear == maxSize -1) return true;
    return false;
}

void enqueue(int x){
    if(isEmpty()) front=rear=0;
    else rear++;
    queue[rear] = x;
}

int peek_front(){
    return queue[front];
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ", queue[i]);
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();
    printf("\n");
    printf("%d ",peek_front());

    return 0;
}
