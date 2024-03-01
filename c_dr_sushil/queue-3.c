#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define maxsize 10

int queue[maxsize];
int rear = -1, front= -1;
bool isFull(){
    if(front == (rear+1)%maxsize) return true;
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
    else rear=(rear+1)%maxsize; // for normal conditions
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
    front = (front+1)%maxsize;
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

int main(){
    int ch;
    while (true)
    {
        printf("\n");
        printf("Give your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n");
        scanf("%d",&ch);
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
            exit(0);
            break;
        default:
            printf("Enter a valid value\n");
            break;
        }
    }
    
    return 0;
}
