#include<stdbool.h>
#include<string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool inStr(char a[], char key){
    int i=0;
    while(a[i]!='\0'){
        if(a[i]==key) return true;
        i++;
    }
    return false;
}

bool isAnagram(char a[], char b[]){
    if(strlen(a)!=strlen(b)) return false;
    int i=0;
    while(a[i]!='\0'){
        if(!inStr(b, a[i])) return false;
        i++;
    }
    return true;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int i,j;
    // char arr[10000][10000][100];
    int dim1 = 10000;
    int dim2 = 10000;
    int dim3 = 100;
    // Allocate memory for the 3D array
    char ***arr = (char ***)malloc(dim1 * sizeof(char **));

    *returnSize=0;
    for(i=0;i<strsSize;i++){
        bool flag = false;
        strcpy(arr[*returnSize][*returnColumnSizes[i]],strs[i]);
        for(j=i+1;j<strsSize;j++){
            if(isAnagram(strs[i],strs[j])){
                flag = true;
                if(j!=strsSize-1){
                    strcpy(arr[*returnSize][*returnColumnSizes[i]++],strs[j]);
                    for(int k=j;k<strsSize;k++){
                        strs[k]=strs[k+1];
                    }
                    strsSize--;
                }
                else strsSize--;
            }
        }
        if(flag) *returnSize++;
    }
    return arr;
}