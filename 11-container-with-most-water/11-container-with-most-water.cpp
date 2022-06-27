class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, l = 0, r = height.size()-1;
        while(l<r){
            ret = max(ret, min(height[l], height[r])*(r-l));
            height[l]<height[r] ? l++ : r--;
        }
        return ret;
    }
};