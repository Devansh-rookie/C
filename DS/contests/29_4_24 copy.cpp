#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<iostream>
using namespace std;
void shift(char *s, int l, int r){
    char temp = s[r];
    for(int j=r;j>l;j--){
        s[j]= s[j-1];
    }
    s[l] = temp;
    // return s; 
}

int cost(char *s){
    int i=0;
    int r=0;int l=0;
    int ans=0;
    bool flag = false;
    while(s[i]!='\0'){
        if(!flag && s[i]=='1'){
            l=i;
            flag = true;
        }
        if(flag && s[i]=='0'){
            r=i;
            shift(s, l, r);
            ans += r-l+1;
            flag = false;
            // l++;
            i=l;
        }
        i++;
    }
    return ans;
}

int main()
{
    char s[200000];
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        // fgets(s ,200000, stdin);
        cin>>s;
        // gets(s);
        // char s[]= "01101001";
        cout<<cost(s)<<endl;
        // n--;
    }
    getchar();
    return 0;
}