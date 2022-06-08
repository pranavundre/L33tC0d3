

int arraySign(int* nums, int numsSize){
    int neg=0, i=0;
    while(i<numsSize){
        if(nums[i]<0)
            neg=neg+1;
        else if(nums[i]==0)
            return 0;
        i++;
    }
    if(neg%2==0)
        return 1;
    else
        return -1;
}