#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
// // int main(){
// //     // printf("%d", (int)('5'-48));

// //     return 0;
// // }

// // int reverseDigits(int num) 
// // { 
// //     int rev_num = 0; 
// //     while (num > 0) { 
// //         rev_num = rev_num * 10 + num % 10; 
// //         num = num / 10; 
// //     } 
// //     return rev_num; 
// // }

// // int myAtoi(char* s) {
// //     int num=0, i=0, dig=0;
// //     bool flag=false;
// //     while(s[i]!='\0'){
// //         if(s[i]==' '){ 
// //             i++;
// //             continue;
// //         }
// //         else if(s[i]=='-'){ 
// //             i++;
// //             flag=true;
// //             continue;
// //         }
// //         else if(s[i]>='0' && s[i]<='9'){
// //             int x = (int)(s[i]-48);
// //             num = num + x*pow(10,dig);
// //             dig++;
// //             if(!(s[i+1]>='0' && s[i+1]<='9')){
// //                 break;
// //             }
// //         }
// //         i++;
// //     }
// //     num = reverseDigits(num);
// //     if(flag) return -num;
// //     else return num;
// // }
// int reverseDigits(int num) 
// { 
//     int rev_num = 0; 
//     while (num > 0) { 
//         rev_num = rev_num * 10 + num % 10; 
//         num = num / 10; 
//     } 
//     return rev_num; 
// }

// int myAtoi(char* s) {
//     long int num=0, i=0, dig=0;
//     bool flag=false;
//     while(s[i]!='\0'){
//         if(s[i]==' '){ 
//             i++;
//             continue;
//         }
//         else if(s[i]=='-'){ 
//             i++;
//             flag=true;
//             continue;
//         }
//         else if(s[i]>='0' && s[i]<='9'){
//             long int x = (long int)(s[i]-48);
//             num = num + x*pow(10,dig);
//             dig++;
//             if(!(s[i+1]>='0' && s[i+1]<='9')){
//                 break;
//             }
//         }
//         // for words before the number otherwise it would give all numbers even after the words
//         else{
//             break;
//         }
//         i++;
//     }
//     num = reverseDigits(num);
//     if(num > INT_MAX && flag) return -INT_MAX;
//     else if(!flag && num> INT_MAX) return INT_MAX;
//     if(flag) return -num;
//     else return num;
// }
// long int reverseDigits(long int num) 
// { 
//     long int rev_num = 0; 
//     while (num > 0) { 
//         rev_num = rev_num * 10 + num % 10; 
//         num = num / 10; 
//     } 
//     return rev_num; 
// }

long int arr_to_int(int arr[],int dig){
    long int num=0;
    for(int i=0;i<dig;i++){
        num+= arr[i]*pow(10,dig-i-1);
    }
    return num;
}

int myAtoi(char* s) {
    long int num=0, i=0, dig=0;
    int b[200];
    int flag_min=0, flag_plus=0;
    bool found_num= false, broken=false, found_char = false, found_0=false;
    while(s[i]!='\0'){
        if(s[i]==' '){ 
            if(found_0||found_num||flag_min||flag_plus) return 0;
            i++;
            continue;
        }
        else if(s[i]=='-'){ 
            i++;
            flag_min++;
            if (found_0) return 0;
            continue;
        }
        else if(s[i]=='+'){ 
            if(found_0)return 0;
            i++;
            flag_plus++;
            continue;
        }
        
        else if(!found_num && s[i]=='0'){
            i++;
            found_0=true;
            continue;
        }
        else if(s[i]>='0' && s[i]<='9'){
            found_num = true;
            long int x = (long int)(s[i]-48);
            // num = num + x*pow(10,dig);
            b[dig]= x;
            dig++;
            if(dig>11){
                if(flag_min==0) return INT_MAX;
                else return INT_MIN;
            }
            if(!(s[i+1]>='0' && s[i+1]<='9')){
                if(s[i+1]>'9') found_char = true;
                broken =true;
                break;
            }
        }
        // for words before the number otherwise it would give all numbers even after the words
        else if(!isdigit(s[i])&& (!found_num)){
            break;
        }
        i++;
    }
    // while(s[i]!='\0'){
    //     if(found_num&& broken&& found_char&&s[i]>='0'&& s[i]<='9'){
    //         return 0;
    //         // break;
    //     }
    //     i++;
    // }
    num = arr_to_int(b, dig);
    if(flag_min>1||flag_plus>1)return 0;
    if(flag_min>0 && flag_plus>0) return 0;
    if(num > INT_MAX && flag_min>0) return -INT_MAX-1;
    else if(!flag_min && num> INT_MAX) return INT_MAX;
    if(flag_min) return -num;
    else{
        return num;
    }
}
