#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void substring(char str[],char to_check[]){
    bool flag=false;
    bool flag2= false;
    int len_str= strlen(str);
    int len_to_check= strlen(to_check);
    for(int i=0;str[i]!='\0';i++){
        flag = false;
        if(str[i]==to_check[0]){
            for(int j=0;to_check[j]!='\0';j++){
                if(str[i+j]==to_check[j]){
                    flag=true;
                }
                else{
                    flag= false;
                    break;
                }
            }
        }
        if(flag){ 
            printf("String found at %d",i);
            bool flag2=true;
        }
    }
    if(!flag2) printf("Not found");
}

int main(){
    char str[100],abc[100];
    gets(str);
    gets(abc);
    substring(str,abc);
    return 0;
}