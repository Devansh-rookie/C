long int char_to_int(char nums[]){
    int i=0,j=0, num=0;
    int len = strlen(nums);
    int arr[len];
    for(i=0;i<len;i++){
        arr[i]=(int)(nums[i]-48);
    }
    for(j=0;j<len;j++){
        num += arr[j]*pow(10,i-j-1);
    }
    return num;
}

char* int_to_char_arr(long int num){
    char nums[200];
    long int op_num= num;
    int dig=0;
    while(op_num!=0){
        nums[dig]=(char)(op_num%10+48);
        op_num/=10;
        dig++;
    }
    for(int i=0;i<dig/2;i++){
        char temp = nums[i];
        nums[i]= nums[dig-i-1];
        nums[dig-i-1]=temp;
    }
    nums[dig]='\0';
    return nums;
}

char* multiply(char* num1, char* num2) {
    long int val =char_to_int(num1)*char_to_int(num2);
    char * str = int_to_char_arr(val);
    return str;
}