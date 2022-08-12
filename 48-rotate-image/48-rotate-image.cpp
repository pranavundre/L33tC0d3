class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int swap;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix.size(); j++){
                if(i!=j){
                    swap = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = swap;
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
            // for(int j = 0; j < matrix.size()/2; j++){
            //     swap = matrix[i][j];
            //     matrix[i][j] = matrix[i][matrix.size()-j-1];
            //     matrix[i][matrix.size()-j-1] = swap;
            // }
        }
    }
};