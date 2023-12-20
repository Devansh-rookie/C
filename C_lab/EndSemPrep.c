#include<stdio.h>

typedef struct date{
    int date;
    int month;
    int year;
}date;

void compare_date(){
    date d1,d2;
    printf("Enter the date, month and year(in numbers)\n");
    scanf("%d %d %d",&d1.date,&d1.month,&d1.year);
    printf("Enter the date, month and year(in numbers)\n");
    scanf("%d %d %d",&d2.date,&d2.month,&d2.year);
    if(d1.date==d2.date&&d1.month==d2.month&&d1.year==d2.year){
        printf("EQUAL\n");
    }
    else printf("UNEQUAL\n");
}

// Yes relational operators can be used on a string 
// but it will be done lexicographically which means that
// it will use ASCII code starting from the first letter and going
// on till the last and if the strings are A and B so if 
// A[0]>B[0](in ASCII code) the the function of Strcmp
// would return the value of 1 is A[0] is smaller
// then -1 other wise if its equal then it will go to A[1]
// and B[1] then again and again go through if all are equal
// then it would have 0 otherwise 1 or -1 as shown above.

// do array question find how many times a thing has been repeated

void remove_except_alpha(){
    char a[100],b[100];
    // gets(a);
    int i=0,j=0;
    fgets(a,100,stdin);// stdin for input
    while(a[i]!='\0'){// copying the alphabet values
    // another method can be to delete the rest
        if((a[i]<=90&&a[i]>=65)||(a[i]<=122&&a[i]>=97)){
            b[j]=a[i];
            j++;
            }
        i++;
    }
    puts(b);
}

int main(){
    // remove_except_alpha();
    
    return 0;
}