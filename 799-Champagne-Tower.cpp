class Solution {
public:
    vector<vector<double>> tower;
    void solve(int& q, int row){
        if(row == 100) return;

        vector<double> &currRow = tower[row], newRow(row + 2, 0);
        
        newRow[0] = currRow[0] > 1 ? (currRow[0] - 1)/2 : 0;
        newRow[row+1] = currRow[row] > 1 ? (currRow[row] - 1)/2 : 0;

        for(int i = 1; i <= row; i++){
            double l = currRow[i-1] > 1 ? (currRow[i-1] - 1)/2 : 0;
            double r = currRow[i] > 1 ? (currRow[i] - 1)/2 : 0;
            currRow[i-1] = currRow[i-1] < 1 ? currRow[i-1] : 1;
            newRow[i] = l + r;
        }
        currRow[row] = currRow[row] < 1 ? currRow[row] : 1;

        tower.push_back(newRow);
        solve(q, row+1);
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;
        vector<double> firstRow = {(double)poured};
        tower.push_back(firstRow);
        solve(query_row, 0);
        return tower[query_row][query_glass];
    }
};
