class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnts(26, 0);
        int n = s.size();
        if(n == 0) return t[0];
        for(int i = 0; i < n; i++){
            cnts[s[i] - 'a']++;
            cnts[t[i] - 'a']--;
        }
        cnts[t[n] - 'a']--;
        for(int i = 0; i < 26; i++) if(cnts[i] != 0) return 'a' + i;
        return 'a';
    }
};
