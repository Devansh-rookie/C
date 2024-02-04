void merge(int a[],int b[],int n,int m, int c[]){
    int i=0,j=0,k=0;
    // int c[n+m];// no need of it as we are having c and size is nums1Size+nums2Size
    while(i<n&& j<m){
        if(a[i]>=b[j]){
            c[k]=b[j];
            j++;
            k++;
        }
        else{
            c[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;
        k++;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums[nums1Size+nums2Size];
    merge(nums1, nums2, nums1Size, nums2Size, nums);
    if((nums1Size+nums2Size)%2!=0){
        // if is for odd number of total digits
        return (double)nums[(nums1Size+nums2Size)/2];
    }
    else return ((double)nums[(nums1Size+nums2Size)/2-1]+(double)nums[(nums1Size+nums2Size)/2])/2.0;
    // else is for even number of total digits
}
