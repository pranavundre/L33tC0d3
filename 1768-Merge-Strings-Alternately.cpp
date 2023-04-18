class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, j = 0;
        while(i<word1.size() && j<word2.size()){
            if(res.size()%2 == 0) res += word1[i++];
            else res += word2[j++];
        }
        if(i == word1.size()) res += word2.substr(j);
        else res += word1.substr(i);
        return res;
    }
};
