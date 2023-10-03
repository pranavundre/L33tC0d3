class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        vector<int> occ(101, 0);
        for(int i : nums) occ[i]++;
        for(auto i : occ) res += (i*(i-1))/2;
        return res;
    }
};
