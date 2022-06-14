class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n-2; layer >= 0; layer--) // For each layer
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
        
        
        
        
        
        
        
        // int sum = triangle[0][0];
        // int i = 0;
        // int j = 0;
        // while(i<(triangle.size()-1)){
        //     if(triangle[i+1][j] > triangle[i+1][j+1])
        //         j = j + 1;
        //     i = i + 1;
        //     sum += triangle[i][j];
        // }
        // return sum;
    }
};