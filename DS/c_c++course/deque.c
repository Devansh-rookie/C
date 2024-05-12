#include<stdio.h>
#include<stdbool.h>

#define maxSize 100

typedef struct dequeue {
    int front;
    int rear;
    int queue[maxSize];
} dequeue;

void insertFront(dequeue *q, int val) {
    if((q->front == q->rear + 1) || (q->front == 0 && q->rear == maxSize - 1)) {
        printf("Overflow");
        return;
    }

    if(q->front == q->rear && q->front == -1) {
        q->front = q->rear = 0;
        q->queue[q->front] = val;
        return;
    }
    if(q->front == 0) {
        q->front = maxSize - 1;
        q->queue[q->front] = val;
    } else {
        q->front--;
        q->queue[q->front] = val;
    }
}

void insertRear(dequeue *q, int val) {
    if((q->front == 0 && q->rear == maxSize - 1) || (q->front == q->rear + 1)) {
        printf("Overflow");
        return;
    }

    if(q->front == q->rear && q->front == -1) {
        q->front = q->rear = 0;
        q->queue[q->rear] = val;
        return;
    }
    if(q->rear == maxSize - 1) {
        q->rear = 0;
        q->queue[q->rear] = val;
    } else {
        q->rear++;
        q->queue[q->rear] = val;
    }
}

void display(dequeue q) {
    if(q.front == q.rear && q.front == -1) {
        printf("Underflow");
        return;
    }
    printf("\n");
    int i = q.front;
    while(i != q.rear) {
        printf("%d ", q.queue[i]);
        i = (i + 1) % maxSize;
    }
    printf("%d ", q.queue[q.rear]);
    printf("\n");
}

int main() {
    dequeue q;
    q.front = q.rear = -1;
    insertFront(&q, 10);
    insertRear(&q, 20);
    insertRear(&q, 30);
    display(q);
    return 0;
}
