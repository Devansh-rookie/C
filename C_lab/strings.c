#include<stdio.h>
#include<string.h>
int len(char s[]){
    int l;
    for(int i=0;s[i]!='\0';i++){
        l++;
    }
    return l;
}
void concatenate(){
    char s1[100],s2[100],s3[100];
    int i,j;
    gets(s1);
    // printf("%c",s1[1]);
    gets(s2);
    // printf("%c",s2[]);
    for(i=0;s1[i]!='\0';i++) s3[i]=s1[i];
    for(j=0;s2[j]!='\0';j++) s3[j+i]=s2[j];
    s3[j+i]='\0';// important add null character in the end.
    // printf("%d",len(s1));
    puts(s3);
}

void reversal(){
    char s[100];
    int l;
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        l++;
    }
    for(int i=0;i<l/2;i++){
        char temp = s[i];
        s[i]=s[(l-1)-i];
        s[l-1-i]=temp;
    }
    puts(s);
}

void append(){// putchar and getchar
    char s1[200],s2[100];
    gets(s1);
    gets(s2);
    int l,i;
    for( i=0;s1[i]!='\0';i++) l++;
    printf("%d",l);
    for( i=0;s2[i]!='\0';i++){

        s1[l+i]=s2[i];
        printf("%d",i);
    }
    s1[l+i]='\0';
    puts(s1);
}

void salting(){
    char main_str[300],salt[100],where[100];
    int i,j;
    gets(main_str);
    gets(salt);
    gets(where);
    for(i=0;;i++){
        for(j=0;;j++){

        }
    }
}

int main(){
    // concatenate();
    // reversal();
    append();
    // int a=5,c;
    // c=++a+ a++;
    // printf("%d %d",c,a);
    return 0;
}