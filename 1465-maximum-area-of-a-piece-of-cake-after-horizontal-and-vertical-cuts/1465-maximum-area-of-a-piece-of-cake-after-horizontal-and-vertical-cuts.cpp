class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = 0, maxw = 0, m = 1000000007;
        
        for(int i = 0; i < horizontalCuts.size()-1; i++)
            maxh = max(maxh, horizontalCuts[i+1]-horizontalCuts[i]);
        
        for(int i = 0; i < verticalCuts.size()-1; i++)
            maxw = max(maxw, verticalCuts[i+1]-verticalCuts[i]);
        
        return (1LL*maxh*maxw) % m;
    }
};