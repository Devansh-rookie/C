#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>
#include<string.h>
#define maxSize 100
char stk[maxSize];
int top = -1;


// void strrev(char* str)
// {
//     // if the string is empty
//     if (!str) {
//         return;
//     }
//     // pointer to start and end at the string
//     int i = 0;
//     int j = strlen(str) - 1;
 
//     // reversing string
//     while (i < j) {
//         char c = str[i];
//         str[i] = str[j];
//         str[j] = c;
//         i++;
//         j--;
//     }
// }

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void strrev(char* str) {
    int len = strlen(str);
    int start = 0;
    int end = len - 1;
    while (start < end) {
        if (str[start] == '(' && str[end] == ')') {
            start++;
            end--;
        } else if (str[start] == '(' && str[end] != ')') {
            end--;
        } else if (str[start] != '(' && str[end] == ')') {
            start++;
        } else {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
}
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


bool isOperator(char c){
    if(c == '^'||c == '/' || c == '*'||c == '+' || c == '-') return true;
    return false;
}

bool isEmpty(){
    if(top== -1) return true;
    return false;
}

bool isFull(){
    if(top == maxSize-1) return true;
    return false;
}

void push(char val){
    if(top == maxSize-1) return;
    stk[++top]= val;
}

char pop(){
    if(!isEmpty()){
        char a = stk[top--];
        return a;
    }
}

char * inToPre(char *s){
    int i=0;
    // push('(');
    char ans[100];
    int j=0;
    while(s[i]!='\0'){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            // printf("%c", s[i]);
            ans[j++] = s[i];
        }
        else if(s[i]=='('){
            push(s[i]);
        }
        else if(s[i]==')'){
            char x= pop();
            while(x!='('){
                // printf("%c", x);
                ans[j++] = x;
                x = pop();
            }
        }
        else if(isOperator(s[i])){
            if(prec(stk[top])>prec(s[i])){
                while (prec(stk[top])>prec(s[i]))
                {
                    char x = pop();
                    // printf("%c", x);
                    ans[j++] = x;
                }
            }
            push(s[i]);
        }
        i++;
    }
    while(!isEmpty()){
        if(stk[top]!='(')
            // printf("%c", pop());
            ans[j++] = pop();
        else pop();
    }
    ans[j++] = '\0';
    strrev(ans);
    // return ans;
    puts(ans);
}

int main(){
    char s[maxSize];
    fgets(s,maxSize,stdin);
    strrev(s);
    inToPre(s);
    return 0;
}
