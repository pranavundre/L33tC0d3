class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ret = 0;
        multiset<int> ms;
        for(int i = 0; i < nums1.size(); i++)
            ms.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            ms.insert(nums2[i]);
        
        auto it = ms.begin();
        if(ms.size()%2 != 0){
            for(int i = 0; i < (ms.size()/2); i++)
                it++;
            ret = *it;
        }
        else{
            auto rit = ms.rbegin();
            for(int i = 0; i < (ms.size()/2); i++){
                it++;
                rit++;
            }
            ret += *it;
            ret += *rit;
            ret /= 2;
        }
            
        return ret;
    }
};