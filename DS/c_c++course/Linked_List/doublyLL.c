#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    struct Node * prev;
    int val;
    struct Node * next;
} Node;

Node * first = NULL;

// in C++ t= new Node
void createLL(int arr[], int n){
    Node * t;Node * last;
    int i;
    first = (Node*)malloc(sizeof(Node));
    // for first element
    first->prev= first->next= NULL;
    first->val=arr[0];
    last = first; // then make last->next = NULL, "IMP::in the end here use it for traversing in the loop"

    // now the loop to actually make the LL

    for (i=1 ; i<n; i++)
    {
        t= (Node*)malloc(sizeof(Node));

        last->next=t;// next's linking is always done by this piece of code
        t->prev= last;
        t->val=arr[i];
        last = t;
    }
    last->next = NULL;
}

void displayLL(Node * p){
    while(p!=NULL){
        printf("%d ", p->val);
        p= p->next;
    }
}

int lengthLL(Node * p){
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

void insertLL(Node * p, int val, int index){
    int c=1;
    Node* t = (Node *)malloc(sizeof(Node));
    t->val = val;
    if(index==0){
        t->prev= NULL;
        t->next= p;
        p ->prev = t;
        first = t;
    }

    if(index<0 || index>lengthLL(first)) return;
    // if(index == lengthLL(first)){// or this lengthLL(first) function can be called before hand and stored in some variable and compared directly in order to reduce the time taken to run the program at expense of very little memory
    //     while (p->next!=NULL)
    //     {
    //         p=p->next;
    //     }
    //     p->next= t;
    //     t->prev = p;
    //     t->next =NULL;
    //     return;
    // }

    // Logic 1
    // while (p!=NULL)
    // {
    //     if(c==index){
    //         t->prev = p;
    //         (p->next)->prev= t;
    //         t->next= p->next;
    //         p->next = t;
    //     }
    //     c++;
    //     p=p->next;
    // }

    else{
        for(int i=0;i<index-1;i++){// say index is 7 this loop will move the pointer from 0 to 5 that is 6 times so it would reach right before the place where we have to insert the value as index in our linked list is in such a way.
        // 6 times would make it so it would reach the 6th index so we can continue from there
        // what index we insert should be that new one if index = 3 then the value inserted should have that index
            p=p->next;// this will take the pointer to right before the index where we need to insert the value
        }
        t->prev = p;
        if(p->next!=NULL) (p->next)->prev = t;// otherwise it would give segmentation fault
        t->next = p->next;
        p->next = t;
    }
}

void deleteIndex(Node * p, int index){
    if(index<0 || index >lengthLL(first)-1) return;// or greater than equal to instead of the -1 that is put there
    if(index ==0){
        (p->next)->prev = NULL;
        first = p->next;
        return;
    }
    else{// or else can also be removed as, in the if statement we have a return statement so if it executes the function would be terminated regardless
        for(int i=0;i<index -1; i++){// to ensure we reach the place right before the Node we have to delete
            p=p->next;
        }
        if(p->next->next!=NULL) ((p->next)->next)->prev = p;
        p->next= (p->next)->next;
    }
}

void deleteIndexLogic2(Node * p, int index){
    if(index<0 || index >lengthLL(first)-1) return;// or greater than equal to instead of the -1 that is put there
    if(index ==0){
        (p->next)->prev = NULL;
        first = p->next;
        return;
    }
    else{// or else can also be removed as, in the if statement we have a return statement so if it executes the function would be terminated regardless
        for(int i=0;i<index; i++){// to ensure we reach the place on the Node we have to delete
            p=p->next;
        }
        if(p->next!=NULL) (p->next)->prev = p->prev;
        (p->prev)->next= p->next;
    }
}

void reverseLL(Node * p){
    while(p!=NULL){
        Node * temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL) first = p;// Lazy Evaluation
    }
}

// Circular Doubly Linked List on iPad

int main(){
    int arr[] = {1,3,2,5,6,7,21};
    createLL(arr, 7);

    displayLL(first);
    printf("\n");

    insertLL(first, 123, 7);

    displayLL(first);
    printf("\n");

    deleteIndex(first, 4);

    displayLL(first);
    printf("\n");

    deleteIndexLogic2(first, 6);

    displayLL(first);
    printf("\n");

    reverseLL(first);
    displayLL(first);
    printf("\n");

    printf("\nThe Length is : %d ", lengthLL(first));
    return 0;
}
