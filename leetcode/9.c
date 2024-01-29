#include<stdbool.h>
bool isPalindrome(int x) {
    int dig=0,op_num=x;
    if(x<0) return false;
    else if(x==0) return true;
    while(op_num!=0){
        op_num/=10;
        dig++;
    }
    op_num=x;
    int arr[dig];
    for(int i=0;op_num!=0;i++){
        arr[i]=op_num%10;
        op_num/=10;
    }
    for(int i=0;i<dig;i++){
        if(arr[i]!=arr[dig-i-1]) return false;
    }
    return true;
}

// bool isPalindrome(int x) {
//     int dig=0,op_num=x;
//     if(x<0) return false;
//     else if(x==0) return true;
//     int* arr= (int*)malloc(sizeof(int));
//     for(int i=0;op_num!=0;i++){
//         arr= (int*)realloc(arr, (i+1)*sizeof(int));
//         arr[i]=op_num%10;
//         op_num/=10;
//         dig++;
//     }
//     for(int i=0;i<dig;i++){
//         if(arr[i]!=arr[dig-i-1]) return false;
//     }
//     return true;
// }