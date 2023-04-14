class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0), dpPrev(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[j] = dpPrev[j-1] + 2;
                } else {
                    dp[j] = max(dpPrev[j], dp[j-1]);
                }
            }
            dp.swap(dpPrev);
        }
        return dpPrev[n-1];
    }
    
    // bool isPalindrome(string temp){
    //     for(int i = 0; i < temp.size()/2; i++)
    //         if(temp[i] != temp[temp.size()-i-1]) return false;
    //     return true;
    // }

    // void allSubseq(string &s, int &res, string temp, int index){
    //     if(index == s.size()+1) return;
    //     if(temp.size() > res) if(isPalindrome(temp)) res = temp.size();
    //     allSubseq(s, res, temp+s[index], index+1);
    //     allSubseq(s, res, temp, index+1);
    // }

    // int longestPalindromeSubseq(string s) {
    //     int res = 0;
    //     allSubseq(s, res, "", 0);
    //     return res;
    // }
};
