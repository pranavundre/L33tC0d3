class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        while(res.size() < rowIndex+1){
            res.push_back(1);
            for(int i = res.size()-2; i > 0; i--) res[i] = res[i] + res[i-1];
        }
        return res;
    }
};
