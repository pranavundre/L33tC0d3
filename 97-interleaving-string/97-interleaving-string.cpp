class Solution {
public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.length() + s2.length() != s3.length()){
//             return false;
//         }else if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0){
//             return true;
//         }
        
//         int p1 = 0, p2 = 0, p3 = 0;
        
//         // while(p3<s3.length()){
//         //     if(p1<s1.length() && s1[p1] == s3[p3])
//         //         p1++;
//         //     else if(p2<s2.length() && s2[p2] == s3[p3])
//         //         p2++;
//         //     else if(s1[p1] != s3[p3] && s2[p2] != s3[p3])
//         //         return false;
//         //     p3++;
//         //     // else if(p3==s3.length()-1 && p2==s2.length()-1 && p1==s1.length()-1)
//         // }
        
        
//         for(int i = 0; i < s3.length(); i++){
//             if(p1<s1.length())
//                 if(s3.at(i) == s1.at(p1)){
//                     p1++;
//                     continue;
//                 }
//             if(p2<s2.length())
//                 if(s3.at(i) == s2.at(p2)){
//                     p2++;
//                     continue;
//                 }
//             else
//                 return false;
//         }
        
//         return true;
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        #define S1 (dp[j] && s1[i-1] == s3[i+j-1])
        #define S2 (dp[j-1] && s2[j-1] == s3[i+j-1])
        
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (n + m != k) return false;
        vector<bool> dp(m+1, 0);
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[j] = (i==0 && j==0) ? true : i==0 ? S2 : j==0 ? S1 : S1 || S2;
            }
        }

        return dp[m];
    }
    
};