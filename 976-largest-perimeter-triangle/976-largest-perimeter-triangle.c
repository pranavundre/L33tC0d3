int comparator(const void *p, const void *q) { return (*(int*)p-*(int*)q); }

int largestPerimeter(int* nums, int numsSize){
    qsort((void*)nums, numsSize, sizeof(nums[0]), comparator);
    for (int i=numsSize-1; i>1; i--) 
        if(nums[i] < nums[i-1] + nums[i-2]) 
            return (nums[i] + nums[i-1] + nums[i-2]);
    return 0;
}