bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0];
}

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        
        sort(intr.begin(), intr.end(), sortcol);
        vector<vector<int>> ret;
        
        ret.push_back(intr[0]);
        if(intr.size()==1)
            return ret;
        
        for(int i = 1; i < intr.size(); i++){
            if(intr[i][0] <= ret[ret.size()-1][1])
                ret[ret.size()-1][1] = max(ret[ret.size()-1][1],intr[i][1]);
            else if(intr[i][0]>ret[ret.size()-1][1])
                ret.push_back(intr[i]);
        }
        return ret;
    }
};