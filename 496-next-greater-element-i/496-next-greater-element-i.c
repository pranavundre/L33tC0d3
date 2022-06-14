

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int *returnArr = (int *)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    for(int i = 0; i < nums1Size; i++){
        returnArr[i] = -1;
        for(int j = 0; j < nums2Size; j++)
            if(nums1[i] == nums2[j]){
                int k = j+1;
                while(k < nums2Size){
                    if(nums1[i] < nums2[k]){
                        returnArr[i] = nums2[k];
                        break;
                    }
                    k++;
                }
            }
    }
    return returnArr;
}