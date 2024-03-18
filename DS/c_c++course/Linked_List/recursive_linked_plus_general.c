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
Node* head = NULL;// for circular Linked List

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

void concatenate_twoLL(Node * p, Node *q){
    // p is first and q is second
    while(p!=NULL){
        p=p->next;
    }
    p->next = q;
    q=NULL;
}

void merging_two_LL(Node * first_p , Node *second_p){
    Node * third; Node* last;
    // third is the pointer which is pointing to the start of the final Linked List and last is the pointer which is pointing to the last of the final Linked List
    if(first_p->data>second_p->data){
        third = second_p; // this represents the first element of the final Linked List
        last = second_p; // this represents the last element of the final linked list only one element is here so third and last point on the same value till now
        second_p= second_p->next;
        // which ever is smaller traverse ahead in the Linked List as we did while merging 2 Arrays
        // finally make the last element's next as NULL to assume that if it has ended we just end the linked list
        last->next = NULL;
    }
    else{
        third = first_p;
        last = first_p;
        first_p= first_p->next;
        last->next= NULL;
    }

    while (first_p!=NULL && second_p!=NULL)
    {
        // here third won't be changed as its already made and it represents the first pointer
        if(first_p->data>second_p->data){
            last->next = second_p;
            last= second_p;// the smaller one is to be taken here
            last->next = NULL;// this is just in case its the last
            second_p= second_p->next;
        }
        else{
            last->next = first_p;
            last = first_p;
            last->next = NULL;
            first_p = first_p->next;
        }
    }
    if(first_p!=NULL){
        last->next=first_p;
    }
    else if(second_p!=NULL) last->next= second_p;
    
}

bool hasLoop(Node * head){
    // if the Linked List has a loop then true else false
    Node * slow; Node * fast;
    slow = head;
    fast = head;
    while(slow!=NULL && fast !=NULL){
        if(slow == fast){
            return true;
        }
        slow= slow->next;// 1 step at a time
        fast = fast->next->next;// 2 steps at a time
    }
    return false;
}

void displayCircularLL(Node * p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p!=head);// if we use while with that same condition then the first element won't be printed as p== head there
}

void displayCircularLLRecursive(Node *p){
    static int flag = 0;// as we don't have to initialize it every time the function is called so static will ensure that, or we could have used global variables
    if(p!=NULL|| flag ==0){
        flag =1;
        printf("%d ", p->data);
        displayCircularLLRecursive(p->next);// if we print later and call first then it would print the LL in reverse
    }
    flag = 0;
}

void createCircularLL(int arr[], int n){
    int i;
    struct Node *t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=head; last=head;
    for (i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next; last->next=t;
        last=t;
    }
}

int lengthCircularLL(Node * p){
    int c=0;
    do
    {
        c++;
    } while (p!=head);
    return c;
}

void insertCircularLL(Node * Head, int index, int value){
    int c=0;
    Node* p=Head;
    if(index<0 || index>lengthCircularLL(Head)) return; // exit the function without inserting anything.
    if(index == 0){
        if(head == NULL){
            Node*t =(Node*)malloc(sizeof(struct Node));
            t->data= value;
            head->next =head;// circular here.
            return;// exit the function
        }
        while(p->next!=head) p=p->next;
        Node*t =(Node*)malloc(sizeof(struct Node));
        t->data= value;
        t->next=p->next;// here p->next is head so that can also be used instead of p->next
        p->next = t;// head can also point to 't' if needed its also the same if to add it in the end, after the last Node.
        return;// exit the function
    }
    do{
        if(c==index){
            Node*t =(Node*)malloc(sizeof(struct Node));
            t->data= value;
            t->next=p->next;
            p->next = t;
            return;// exit the function
        }
        c++;
        p=p->next;
    }while(p!=head);
    return;
}

int deleteCircularIndex(Node * Head, int index){// -1 means not done, 1 means done
    int c=0;// 0th index would mean the first element in this representation that we'll follow
    Node*p = Head;
    Node*t =(Node*)malloc(sizeof(struct Node));
    if(index<0 || index>lengthCircularLL(Head)) return -1;
    if(c+1==index){// if index is 1, that means the first element, that is the head so head is also changed
        if(head == NULL){
            return -1;
        }
        while(p->next!=head) p=p->next;
        p->next=head->next;// head is unlinked
        head= p->next;// make a new head
        return 1;
    }
    do
    {
        c++;
        if(c==index){
            t->next = p->next;// so p will be unlinked
            return 1;
        }
        t=p;
        p=p->next;
    } while (p!=head);
    return 1;
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


//
/*
Bakchoding in LeetCode 21.

while (first_p != NULL && second_p != NULL) {
    if (first_p->val > second_p->val) {
        last->next = second_p;
        last = last->next; // Update last
        second_p = second_p->next;
    } else {
        last->next = first_p;
        last = last->next; // Update last
        first_p = first_p->next;
    }
}

// Append remaining nodes (if any)
if (first_p != NULL) {
    last->next = first_p;
} else {
    last->next = second_p;
}

return third;

*/