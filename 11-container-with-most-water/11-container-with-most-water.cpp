class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ret = 0, l = 0, r = height.size()-1;
        
        while(l<r){
            ret = max(ret, min(height[l], height[r])*(r-l));
            
            height[l]<height[r] ? l++ : r--;
        }
        
        return ret;
        
        
        // for(int i = 0; i < height.size()-1; i++){
        //     for(int j = i+1; j < height.size(); j++){
        //         ret = max(ret, min(height[i], height[j])*(j-i));
        //     }
        // }
    }
};