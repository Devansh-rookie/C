#include<stdio.h>
#include<string.h>

void reader(){
    int i=0;
    char str[100];
    char ch;
    while(ch!='\n'){// acs as gets
        scanf("%c",&ch);
        str[i]=ch;
        i++;
    }
    str[i]='\0';
    puts(str);
}

void salting(){
    // salt is 123 added at the end
    char str[100];
    // fgets(str,100,stdin);// won't use fgets either because it adds a \n without reason// Won't use gets here as its dangerous for security
    scanf("%s",str);
    strcat(str,"123");// password should be less than or equal to 97
    puts(str);
}

void slicing(){
    char str[100],strnew[100];
    scanf("%s",str);//no need of ampersand here as str is already a pointer because its an array/string(if we add\0 in the end)
    int i,n,m,j=0;//indices
    scanf("%d %d",&n,&m);
    j=0;
    for(i=n;i<=m;i++){// including m
        strnew[j]=str[i];
        j++;
    }
    puts(strnew);
}

int main(){
    // reader();
    // salting();
    // slicing();

    // More questions
    // Check number of vowels.
    // Check whether a Character is present in a string or not.
    return 0;
}
