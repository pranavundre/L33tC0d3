class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ret;
        
        vector<int> a;
        a.push_back(1);
        vector<int> b;
        b.push_back(1);
        b.push_back(1);
        vector<int> c;
        
        ret.push_back(a);
        if(numRows == 1) return ret;
        
        ret.push_back(b);
        if(numRows == 2) return ret;
        
        for(int i = 2; i < numRows; i++){
            c.push_back(1);
            for(int j = 1; j < i; j++){
                c.push_back(b[j]+b[j-1]);
            }
            c.push_back(1);
            ret.push_back(c);
            // a.swap(b);
            c.swap(b);
            c.clear();
        }
        return ret;
    }
};


// a = 1
// b = 2
// c = 3

// a swap b
// a = 2
// b = 1
// c = 3

// b swap c
// a = 2
// b = 3
// c = 1