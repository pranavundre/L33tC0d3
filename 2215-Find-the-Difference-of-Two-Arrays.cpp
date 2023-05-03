class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<int> n1, n2;
        for (int num : st1) if (st2.count(num) == 0) n1.push_back(num);
        for (int num : st2) if (st1.count(num) == 0) n2.push_back(num);
        return {n1, n2};
    }
};
