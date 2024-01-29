/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    *returnSize=2;// returned size of array
    int *ptr= (int*)malloc(2*sizeof(int));
    // we are typecasting the pointer from void to int* type as malloc originally gives void type of pointer
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                ptr[0]=i;
                ptr[1]=j;
                return ptr;
                break;
            }
        }
    }
}