#include<stdio.h>
int main(){
    char s1[200],s2[100];
    gets(s1);
    gets(s2);
    int l,i;
    for( i=0;s1[i]!='\0';i++) l++;
    // printf("%d",l);
    for( i=0;s2[i]!='\0';i++){
        // printf("hi  ");
        s1[l+i]=s2[i];
        // printf("%d",i);
    }
     s1[l+i]='\0';
    puts(s1);
return 0;
}