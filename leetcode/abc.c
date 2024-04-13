int maxSubArray(int* nums, int numsSize) {
    // for(int i=0;i<numsSize;i++){
    //     sum=0;
    //     for(int j=i;j<numsSize;j++){
    //         sum+=nums[j];
    //         if(sum>max) max = sum;
    //     }
    // }
    // return max;
    int maxSum = INT_MIN;
    int sum=0;
    int currSum= 0;

    for(int i=0;i<numsSize;i++){
        currSum+=nums[i];
        if(currSum>maxSum){
            maxSum= currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}
