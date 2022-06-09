

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* returnArray = malloc(sizeof(int)*2);
    int ptr1 = 0;
    int ptr2 = numbersSize-1;
    *returnSize = 2;
    
    while(ptr1 < ptr2){
        while(numbers[ptr1]+numbers[ptr2] > target)
            ptr2--;
        if(numbers[ptr1]+numbers[ptr2] == target){
            returnArray[0] = ptr1+1;
            returnArray[1] = ptr2+1;
            return returnArray;
        }
        else
            ptr1++;
    }
    return NULL;
}