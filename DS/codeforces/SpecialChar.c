#include<stdio.h>
#include<math.h>


void special_char(int n){
    if(n%2==1){
        printf("NO\n");
        return;
    }
    // if(n%2==0){
        printf("YES\n");
        for(int i=0;i<n/2;i++){
            if(i%2==0) printf("AA");
            else printf("BB");
        }
        printf("\n");
    // }
    // else{

    // }
    return;
}


int main(){
    int no_of_test_case=0;
    scanf("%d",&no_of_test_case);
    int ch;
    for(int i=0;i<no_of_test_case;i++){
        scanf("%d", &ch);
        special_char(ch);
    }
    return 0;
}