int searchInsert(int* nums, int numsSize, int target) {
    int l=0,h=numsSize-1;
    int mid=0;
    if(nums[numsSize-1]<target){
        return numsSize;
    }
    while(l<=h){
        // this <= ensures that even if l==h then is the target is larger than the mid value now that is in smaller test cases =0 then l would change to mid+1 where we can insert the desired value.
        mid = (l+h)/2;
        if(target == nums[mid]) return mid;
        else if(target>nums[mid]){
            l=mid+1;
        }
        else{
            h= mid-1;
        }
    }
    return l;
}