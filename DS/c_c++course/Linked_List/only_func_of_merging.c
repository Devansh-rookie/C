#include<stdio.h>
typedef struct Node{
    int val;
    struct Node* next;
}Node;

// void merge_sorted_LL(Node * p, Node * q){

//     while (q!=NULL && p!=NULL)
//     {
//         if(q->val<=p->val){
//             if(q->next== NULL){

//             }
//             Node * r= q->next;
//             q->next = p;
//             q = r;
//         }
//         else{
//             Node * r= p->next;
//             p->next = q;
//             p=r;
//         }
//         p=p->next;
//         q= q->next;
//     }

//     while (q!=NULL && p==NULL)
//     {
        
//     }
    

// }

// int main(){

//     return 0;
// }

