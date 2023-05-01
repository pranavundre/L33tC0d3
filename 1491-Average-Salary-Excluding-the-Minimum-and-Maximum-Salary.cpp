class Solution {
public:
    double average(vector<int>& s) {
        return (accumulate(s.begin(),s.end(),0.) - *min_element(s.begin(),s.end()) - *max_element(s.begin(), s.end()))/(s.size()-2);
    }
};

class Solution {
public:
    double average(vector<int>& salary) {
        double res = 0;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i : salary){
            res += i;
            mx = max(mx, i);
            mn = min(mn, i);
        }
        return (res-mx-mn)/(salary.size()-2);
    }
};
