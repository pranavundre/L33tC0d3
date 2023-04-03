class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        sort(p.begin(), p.end());
        vector<int> ret;
        for(int i = 0; i < s.size(); i++){
            int l = 0, h = p.size() - 1;
            while(l <= h)
                if((long long)s[i]*p[((l+h)/2)] >= suc) h = ((l+h)/2)-1;
                else l = ((l+h)/2)+1;
            ret.emplace_back(p.size()-l);
        }
        return ret;
    }
};
