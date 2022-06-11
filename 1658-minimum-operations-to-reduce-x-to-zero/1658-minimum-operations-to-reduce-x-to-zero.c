

int minOperations(int* nums, int numsSize, int x){
    
    /*
     * You are given an integer array nums and an integer x. 
     * In one operation, you can either remove the leftmost or the 
     * rightmost element from the array nums and subtract its value from x. 
     *
     * Note that this modifies the array for future operations.
     * 
     * Return the minimum number of operations to reduce x to 
     * exactly 0 if it is possible, otherwise, return -1.
     */
    
    /*
     *  Input:
     *      nums, integer array
     *      numsSzie, size of array
     *      x, integer
     *
     *      1 <= nums.length <= 100000
     *      1 <= nums[i] <= 10000
     *      1 <= x <= 1000000000
     */
    
    /*
     *  Algorithm:
     *
     *      According to the hints, should find the maximum subarray
     *      (1) sum of nums = SUM
     *      (2) we should find a longest subarray where it's sum value is equal to SUM - X
     *      (3) Assume the length of longest subarray is MAX, 
     *          - the minimal operation to reduce X to zero is numsSize - MAX
     *
     *      Example,
     *
     *      nums = [7, 9, 11, 13, 5, 6, 9], x = 49, 7 items
     *      sum(nums) = 60, 60 - 49 = 11
     *
     *      There are 2 subarrays have sum value equal to 11
     *      [11], [5, 6], the sencond one is longest subarray, length = 2
     *      the minimal operation to reduce X to zero is 7 - 2 = 5
     *
     *      The sliding window method for finding longest subarray with sum value  11
     *
     *      nums = [7, 9, 11, 13, 5, 6, 9]
     *
     *      (1) [7]         i = 0, j = 0, tmp = 7, < 11
     *      (2) [7,9]       i = 0, j = 1, tmp = 16, > 11
     *      (3) [9]         i = 1, j = 1, tmp = 9, < 11      
     *      (4) [9, 11]     i = 1, j = 2, tmp = 20, > 11
     *      (5) [11]        i = 2, j = 2, tmp = 11, macthed, current longest subarray = 1
     *      (6) [13]        i = 3, j = 3, tmp = 13, > 11
     *      (7) [5]         i = 4, j = 4, tmp = 5, < 11
     *      (8) [5, 6]      i = 4, j = 5, tmp = 11, matched, current longest subarray = 2
     *      (9) [9]         i = 6, j = 6, tmp = 9 < 11
     *
     */
    
    int sum = 0;
    int tmp = 0;
    int max = INT_MIN;
    
    /* Sum of array */
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    /* It's impossible to find a solution if sum(nums) is less than x */
    if (sum < x) {
        return -1;
    }
    /* If sum(nums) is equal to x, we must subtract all values in the array from x to reduce x to zero */
    else if (sum == x) {
        return numsSize;
    }

    sum -= x;
    
    /* Find longest subarray which sum is equal to sum - X by sliding window method */
    for (int i = 0, j = 0; j < numsSize; ) {
        
        tmp += nums[j];
        
        /* sum(subarray) is euqal to target, right shift current window */
        if (tmp == sum) {
            if (j - i + 1 > max) {
                max = j - i + 1;
            }
            
            tmp -= nums[i];
            i++;
            j++;
        }
        /* sum(subarray) is larger than target, shift left index to right (make the window narrower) */
        else if (tmp > sum) {
            tmp -= nums[i];
            tmp -= nums[j];
            i++;
        }
        /* sum(subarray) is less than target, shift right idex to right (make the window wider) */
        else {
            j++;
        }
    }

    /*
     *  Output:
     *      Return the minimum number of operations to reduce x to 
     *      exactly 0 if it is possible, otherwise, return -1.
     */
    
    return (max == INT_MIN) ? -1 : (numsSize - max);
    
    
    
    
    
    
//     int ptr1 = 0;
//     int ptr2 = numsSize-1;
//     int cnt = 0;
        
//     while(ptr1<ptr2 && x!=0){
//         if(nums[ptr1] > x && nums[ptr2] > x){
//             return -1;
//         }
//         else if(nums[ptr1] <= x && nums[ptr2] > x){
//             x = x - nums[ptr1];
//             ptr1++;
//             cnt++;
//         }
//         else if(nums[ptr1] > x && nums[ptr2] <= x){
//             x = x - nums[ptr2];
//             ptr2--;
//             cnt++;
//         }
//         else{
//             if(nums[ptr1]>nums[ptr2] && nums[ptr1]<=x){
//                 x -= nums[ptr1];
//                 ptr1++;
//             }else{
//                 x -= nums[ptr2];
//                 ptr2--;
//             }
//             cnt++;
//         }
//     }
//     if(x==0)
//         return cnt;
//     else
//         return -1;
//     return 0;
}