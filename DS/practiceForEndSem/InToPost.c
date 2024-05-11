#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

typedef struct node
{
    char val;
    struct node * next;
} node;

bool isEmpty(node * first){
    if(first == NULL) return true;
    return false;
}

void push(node ** first, node** last, char val){// insertAtLast
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    t->next = NULL;
    if(isEmpty(*first)){
        (*first) = t;
        (*last)= t;
        return;
    }
    (*last)->next = t;
    return;
}

node * pop(node ** first, node ** last){
    if(isEmpty(*first)) return NULL;
    if((*first)->next == NULL){
        node * t = *first;
        (*first) = NULL;
        (*last)=NULL;
        return t;
    }
    node * p = *first;
    while((p)->next->next != NULL){
        p=p->next;
    }
    node * t = p->next;
    p->next = NULL;
    (*last) = p;
    return t;
}

node * peek(node * first, node * last){
    if(isEmpty(first)) return NULL;
    return last;
}

bool isOperator(char c){
    if(c == '+' || c=='-'||c == '*'|| c=='/'||c == '^') return true;
    return false;
}

int priorityOperator(char c){
    if(c == '+' || c=='-') return 1;
    else if(c == '*'|| c=='/') return 2;
    else if(c == '^') return 3;
    return 0;
}

void display(node * first){
    while(first!=NULL){
        printf("%c", first->val);
        first = first->next;   
    }
}

void InfixToPostfix(char *s, node ** first, node ** last){
    char ans[100];
    int i=0;
    int j=0;
    // push(first,last, '(');
    while(s[i]!='\0'){
        if(s[i]=='('){
            push(first, last, s[i]);
        }
        else if((('a'<=s[i] && 'z'>=s[i])||('A'<=s[i] && 'Z'>=s[i]))){
            // push(first, last, s[i]);
            ans[j++] = s[i];
        }
        else if(isOperator(s[i])){
            // if(!isEmpty(*first) && (priorityOperator((peek(*first,*last))->val)>=priorityOperator(s[i]))){
            //     ans[j++]= pop(first, last)->val;
            // }
            // push(first,last,s[i]);
            if(isEmpty(*first)){
                push(first, last, s[i]);
                i++;
                continue;
            }
            node * x= (peek(*first,*last));
            //
            while(!isEmpty(*first) && (priorityOperator((peek(*first,*last))->val)>=priorityOperator(s[i]))){
                ans[j++]= (pop(first,last))->val;
                // x = (pop(first,last));
            }
            // push(first, last, x->val);
            push(first,last,s[i]);
        }
        else if(s[i] == ')'){
            node * t = pop(first, last);
            while(t!=NULL && t->val != '('){
                ans[j++] = t->val;
                t = pop(first, last);
            }
            // pop(first,last);
        }
        
        printf("\n");
        int k=0;
        // while(k<=i){
        //     printf("%c",s[k]);
        //     k++;
        // }
        printf("%c", s[i]);
        printf("\t\t");
        display(*first);
        printf("\t\t");
        // puts(ans);
        printf("%s", ans);
        printf("\n");
        
        i++;
    }
    while(!isEmpty(*first)){
        ans[j++]= pop(first,last)->val;
        printf("\n");
        printf("\t\t");
        display(*first);
        printf("\t\t");
        puts(ans);
        printf("\n");
    }
    ans[j++]= '\0';
    // return ans;
    printf("\nThe answer is:\n");
    puts(ans);

}

int main(){
    node * first = NULL;
    node * last = NULL;
    char s[100];
    printf("What is the Infix Expression: ");
    fgets(s,100, stdin);
    printf("String\t\tStack\t\tExp");
    InfixToPostfix(s, &first, &last);
    return 0;
}
