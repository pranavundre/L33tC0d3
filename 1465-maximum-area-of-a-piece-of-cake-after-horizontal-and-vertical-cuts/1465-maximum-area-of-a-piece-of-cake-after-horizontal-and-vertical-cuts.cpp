class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = horizontalCuts[0], maxw = verticalCuts[0], m = 1000000007;
        
        for(int i = 0; i < horizontalCuts.size()-1; i++)
            maxh = max(maxh, horizontalCuts[i+1]-horizontalCuts[i]);
        
        for(int i = 0; i < verticalCuts.size()-1; i++)
            maxw = max(maxw, verticalCuts[i+1]-verticalCuts[i]);
        
        return (1LL*maxh*maxw) % m;
    }
};