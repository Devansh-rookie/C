// OLD

// #include<string.h>
// int strStr(char* haystack, char* needle) {
//     int i=0,j=0;
//     bool flag=false;
//     int len_h=strlen(haystack);
//     int len_n= strlen(needle);
//     if(len_h>=len_n){
//         for(i=0;haystack[i]!='\0';i++){
//             if(haystack[i]==needle[0]){
//                 for(j=0;needle[j]!='\0';j++){
//                     if(haystack[i+j]==needle[j]) flag = true;
//                     else flag=false;
//                 }
//                 if(flag==true) return i;
//             }
//         }
//     }
//     return -1;
// }

// NEW

// #include<string.h>
// int strStr(char* haystack, char* needle) {
//     int i=0,j=0;
//     bool flag=false;
//     int len_h=strlen(haystack);
//     int len_n= strlen(needle);
//     if(len_h>=len_n){
//         for(i=0;haystack[i]!='\0';i++){
//             if(haystack[i]==needle[0]){
//                 flag = true;// assume that the substring is present
//                 for(j=0;needle[j]!='\0';j++){
//                     if(haystack[i+j]!=needle[j]){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag) return i;
//             }
//         }
//     }
//     return -1;
// }