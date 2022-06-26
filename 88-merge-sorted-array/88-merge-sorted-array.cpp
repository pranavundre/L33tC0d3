class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> nums3;
        
//         for(int i = 0; i < m; i++)
//             nums3.push_back(nums1[i]);
        
//         for(int j = 0; j < n; j++)
//             nums3.push_back(nums2[j]);
        
//         sort(nums3.begin(), nums3.end());
//         nums1.swap(nums3);
        
        for(int i = 0; i < n; i++)
            nums1[m+i] += nums2[i];
        sort(nums1.begin(), nums1.end());
        
    }
};