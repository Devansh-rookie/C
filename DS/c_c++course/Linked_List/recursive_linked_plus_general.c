#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first = NULL;
Node *last = NULL;

void create(int a[], int n){
    int i;
    Node *t, *last;
    // linked_list* first = (linked_list*)malloc(sizeof(linked_list)); redeclaration main dikkat
    first = (Node*)malloc(sizeof(Node));
    first->data= a[0];
    first->next= NULL;
    last = first;
    for(i=1;i<n;i++){
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=a[i]; // as the zeroth element is already added to the linked list
        t->next=NULL;
        last->next=t;// this is assigned to the last t/ the pointer of the next object in the last value
        last = t;// this is being assigned to a new t
    }
}

void display(Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        display(p->next);
    }
}

int count_rec(Node *p){// O(n)- Time and O(n)- Space
    if(p!=NULL){
        return count_rec(p->next)+1;
    }
    else return 0;
}

int count(Node *p){// O(n)- Time  and O(1)- Space
    int c=0;
    while (p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}

int sum_iterative(Node *p){
    int sum= 0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int sum_recursive(Node *p){
    if(p!=NULL) return p->data + sum_recursive(p->next);
    else return 0;
}

int max_element_recursive(Node *p){
    if(p!=NULL){
        int x = max_element_recursive(p->next);
        if(x>p->data) return x;
        else return p->data;
    }
    else return INT32_MIN;
}


int max_element_iterative(Node *p){
    int max = INT32_MIN;
    while(p!=NULL){
        if(p->data>max) max = p->data;
        p=p->next;
    }
    return max;
}

Node * linear_search_iterative(Node *p, int key){
    while (p!=NULL)
    {
        if (key==p->data)
        {
            return p;
        }
        else p=p->next;
    }
    return NULL;
}

Node* linear_search_recursive(Node *p, int key){
    if(p!=NULL){
        if(p->data== key) return p;
        else return linear_search_recursive(p->next,key);
    }
    else return NULL;
}

Node * improved_search(Node *p, int key){
    // in this method of improvisation we bring the key to the front/ head we would use 2 pointers here
    Node *q = NULL;
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = first;// only the pointer which would point to the first Node of the linked list.
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void insert_at_index(Node *p, int val, int index){
    if(index>count(first)){
        printf("Index out of range.\n");
        // exit(0);
    }
    else if(index == 0){
        Node *q= (Node*)malloc(sizeof(Node));
        // this q, is just a temporary variable which changes addresses every time so its just to link other memory address another memory address in the heap that is q
        q->data = val;
        q->next = p;// or use p here
        // first = q;
        first=q;
    }
    else{
        Node *t= (Node*)malloc(sizeof(Node));
        t->data=val;
        for(int i=1;i< index;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// create a linked list using insertion at the end

void insert_last(int val){
    Node *t = (Node*)malloc(sizeof(Node));
    t->data= val;
    t->next= NULL;

    if(first== NULL) first= last = t;
    else{
        last->next = t;// this is to link the current Node that is last to the next Node that is t.
        last = t;// then last to t
    }
}


void insertInSortedLL(Node *p, int val){
    // for ascending order
    if(p==NULL){
        Node *t = (Node*)malloc(sizeof(Node));
        first = t;
        t->data=val;
        t->next=p;
        return;
    }
    if(p->data>val){
        Node *t = (Node*)malloc(sizeof(Node));
        t->data=val;
        first = t;
        t->next=p;
        return;
    }
    while(p!=NULL){
        // p->data>= val won't work as it would insert at one after the value
        // if((p->next)->data >= val && p->next!=NULL){
        if(p->next!=NULL && (p->next)->data >= val){// lazy evaluation, first check if its NULL or not then continue otherwise it will give segmentation fault
            // or use the insert function here
            Node *t = (Node*)malloc(sizeof(Node));
            t->data=val;
            t->next = p->next;
            p->next = t;
            break;
        }
        else if(p->next==NULL){
            Node *t = (Node*)malloc(sizeof(Node));
            t->data=val;
            p->next = t;
            t->next= NULL;
            break;
        }
        p=p->next;
    }
}

int deleteNode(Node *p, int index){
    int c=0;
    if(p==NULL) return 0; 
    else if(c==index){
        int x;
        x = first->data;
        first = p->next;
        return x;
    }
    else{
        while (p!=NULL)
        {
            if(c+1 == index){
                int x;
                x = (p->next)->data;
                p->next=(p->next)->next;
                return x;
            }
            c++;
            p=p->next;
        }
    }
    return 0;
}

bool isSorted(Node *p){
    // This is for ascending sort
    if(p==NULL) return true;
    else if(p->next==NULL) return true;// single element is always sorted
    while(p->next!=NULL){
        if(p->data>(p->next)->data) return false;
        p=p->next;
    }
    return true;
}

void removeDuplicates(Node * p){
    // struct ListNode* first= p;
    // this is done because first is needed as p would be at the end while traversing so we would have to return the head of the list again

    while(p->next!=NULL){
        if(p->data==(p->next)->data){
            p->next = (p->next)->next;
            continue;
            // continue means we will not traverse the list here as we have found a duplicate and we will not traverse as long as we don't delete all the duplicate elements in the sorted linked list
        }
        p=p->next;
    }
}

void removeOGandDuplicates(Node * p){
    // struct ListNode* first= p;
    // this is done because first is needed as p would be at the end while traversing so we would have to return the head of the list again
    bool flag = false;
    Node * previous=p;
    while(p->next!=NULL){
        if(p->data==(p->next)->data){
            p->next = (p->next)->next;
            flag = true;
            continue;
            // continue means we will not traverse the list here as we have found a duplicate and we will not traverse as long as we don't delete all the duplicate elements in the sorted linked list
        }
        if(flag){
            previous->next= p->next;
        }
        flag = false;
        previous = p;
        p=p->next;
    }
}

void reverse_LL_using_arr(Node *p){
    while(p!=NULL){

    }
}

void reverseUsingSlidingPointers(Node * p){
    Node * q;Node * r;// here q would be ahead and then q should point to r
    q = NULL;
    r = NULL;
    while(p!=NULL){// as we want to link the last q when p is NULL to r so the last element is linked as well.
        // q->next= r;
        // the code block below represents the traversing of the Linked List using sliding pointers
        r = q;
        q = p;
        p=p->next;
        // for reversing this LL the next line is used
        q->next= r;
    }
    first = q;
}

void recursiveReverseLL_printonly(Node * p){
    if(p!=NULL){
        recursiveReverseLL_printonly(p->next);
        printf("%d ", p->data);

    }
}

// do it again it didn't work with 3 variables, but it didn't have to as when popping from the recursive stack this works well enough
void recursiveFullReverse(Node * p, Node * q){
    if(p!=NULL){
        recursiveFullReverse(p->next, p);
        // now here after all the recursive calls we would be at the last where p is NULL as p->next has been called prolly
        p->next= q;
    }
    else first = q;
}

int main(){
    // int a[5]= {2,1,4,5,3};
    // create(a,5);
    display(first);
    // printf("\n%d", count_rec(first));
    // printf("\n%d", count(first));
    // printf("\n%d", sum_iterative(first));
    // printf("\n%d", sum_recursive(first));
    // printf("\n%d", max_element_iterative(first));
    // printf("\n%d", max_element_recursive(first));
    // printf("\n%p", linear_search_recursive(first, 5));
    // printf("\n%p", linear_search_iterative(first, 8));
    // printf("\n%p", improved_search(first, 5));
    printf("\n");
    // insert_at_index(first,9, 0);
    // insert_at_index(first,1, 1);
    // insert_at_index(first,5, 2);
    insert_last(5);
    insert_last(6);
    insert_last(52);
    insert_last(72);
    insert_last(123);
    display(first);
    printf("\n");
    insertInSortedLL(first, 100);
    insertInSortedLL(first, 120);
    insertInSortedLL(first, 1);
    insertInSortedLL(first, -1);
    display(first);
    printf("\n");
    printf("%d\n",deleteNode(first, 2));
    printf("%d\n",deleteNode(first, 7));
    printf("%d\n",deleteNode(first, 0));
    // insert_at_index(first,10,6);
    display(first);
    printf("\n%d\n",isSorted(first));
    insertInSortedLL(first, 6);
    insertInSortedLL(first, 6);
    insertInSortedLL(first, 6);
    insertInSortedLL(first, 100);
    insertInSortedLL(first, 1);
    display(first);
    removeDuplicates(first);
    printf("\n");
    display(first);
    reverseUsingSlidingPointers(first);
    printf("\n");
    display(first);
    printf("\n");
    recursiveReverseLL_printonly(first);
    printf("\n");
    recursiveFullReverse(first, NULL);
    display(first);
    return 0;
}
