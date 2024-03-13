#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int exp;
    int coeff;
    struct Node * next;
}Node;


Node * first = NULL;
Node * second = NULL;
Node * result = NULL;
Node * lastf = NULL;
Node * lasts = NULL;
Node * lastr = NULL;

Node * linear_search_iterative(Node *p, int key){
    while (p!=NULL)
    {
        if (key==p->exp)
        {
            return p;
        }
        else p=p->next;
    }
    return NULL;
}

int linear_search_iterative_int(Node *p, int key){
    int c=0;   
    while (p!=NULL)
    {
        if (key==p->exp)
        {
            return c;
        }
        p=p->next;
        c++;
    }
    return -1;
}

// int deleteNode(Node *p, int index, Node **fir){
//     int c=0;
//     if(p==NULL) return 0; 
//     else if(c==index){
//         int x;
//         // IMP Note here
//         x = (*fir)->exp;// -> has higher precedence than * so that bracket is required
//         (*fir) = p->next;
//         return x;
//     }
//     else{
//         while (p!=NULL)
//         {
//             if(c+1 == index){
//                 int x;
//                 x = (p->next)->exp;
//                 p->next=(p->next)->next;
//                 return x;
//             }
//             c++;
//             p=p->next;
//         }
//     }
//     return 0;
// }

int deleteNodeSecond(Node *p, int index){
    int c=0;
    if(p==NULL) return 0; 
    else if(index==0){
        int x;
        // IMP Note here
        x = (second)->exp;// -> has higher precedence than * so that bracket is required
        (second) = p->next;
        return x;
    }
    else{
        while (p!=NULL)
        {
            if(c+1 == index){
                int x;
                x = (p->next)->exp;
                p->next=(p->next)->next;
                return x;
            }
            c++;
            p=p->next;
        }
    }
    return 0;
}

// or we could have used the Node ** last as a parameter in only one of the functions and pass different first and last in them directly

void insert_last_infirst(int coeff, int exp){
    Node *t = (Node*)malloc(sizeof(Node));
    t->coeff= coeff;
    t->exp = exp;
    t->next= NULL;

    if(first== NULL) first= lastf = t;
    else{
        lastf->next = t;// this is to link the current Node that is last to the next Node that is t.
        lastf = t;// then last to t
    }
}

void insert_last_insecond(int coeff, int exp){
    Node *t = (Node*)malloc(sizeof(Node));
    t->coeff= coeff;
    t->exp = exp;
    t->next= NULL;

    if(second== NULL) second= lasts = t;
    else{
        lasts->next = t;// this is to link the current Node that is last to the next Node that is t.
        lasts = t;// then last to t
    }
}

void insert_last_in_result(int coeff, int exp){
    Node *t = (Node*)malloc(sizeof(Node));
    t->coeff= coeff;
    t->exp = exp;
    t->next= NULL;

    if(result== NULL) result= lastr = t;
    else{
        lastr->next = t;// this is to link the current Node that is last to the next Node that is t.
        lastr = t;// then last to t
    }
}

void addition(Node * p, Node * q, Node * r){
    bool found = false;
    // assuming that exp is unique in each linked list
    while (p!=NULL)// let's see if q!=NULL is required
    {   
        int index = linear_search_iterative_int(q, p->exp);
        Node *t;
        if(index ==0) found = true;
        if (index!=-1)
        {
            t = linear_search_iterative(q,p->exp);
            insert_last_in_result(t->coeff+p->coeff, p->exp);
            deleteNodeSecond(q, index);
        }
        else if(index==-1){
            insert_last_in_result(p->coeff, p->exp);
        }
        p=p->next;
    }
    if(found) q=q->next;// to skip that first element of the second linked list that is troubling us
    while(q!=NULL){
        insert_last_in_result(q->coeff, q->exp);
        q=q->next;
    }
}

// void display(Node *p){
//     while(p!=NULL){
//         printf("(%d)x^%d +", p->coeff, p->exp);
//         p=p->next;
//     }
// }

void display(Node *p) {
    while (p != NULL) {
        printf("(%d)x^%d", p->coeff, p->exp);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main(){
    insert_last_infirst(10,0);
    insert_last_infirst(10,1);
    insert_last_infirst(10,2);
    insert_last_infirst(10,3);

    insert_last_insecond(5,0);
    insert_last_insecond(5,1);
    insert_last_insecond(5,2);
    insert_last_insecond(5,50);
    printf("First Polynomial: \n");
    display(first);
    printf("\n");

    printf("Second Polynomial: \n");
    display(second);
    printf("\n");

    addition(first, second, result);
    printf("Resultant Polynomial: \n");
    display(result);
    printf("\n");
    return 0;
}
