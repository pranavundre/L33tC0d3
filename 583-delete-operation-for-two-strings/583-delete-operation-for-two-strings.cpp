class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int s1=word1.size(),s2=word2.size();
        int dp[s1+1][s2+1];
        dp[0][0]=0;
        for(int i=0;i<=s1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=s2;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }
        return s1+s2-2*dp[s1][s2];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int w1 = word1.size(), w2 = word2.size();
//         set<int> st;
//         int lcs = 0, s = -1, c=0;
        
//         for(int j = 0; j < w2; j++){
//             for(int i = 0; i < w1; i++){
//                 if(word2[j]==word1[i] && i>s){
//                     s = i;
//                     c++;
//                     int k = i+1, l = j+1, c = 1;
//                     while(k<w1 && l<w2){
//                         if(word2[l]==word1[k])
//                             c++;
//                         }else
//                     }
//                     lcs = max(lcs, c);
//                 }
//             }
//         }
        
        // return w1+w2-lcs*2;
        
        
        // int j = 0, i = 0;
        // while(i<w1 && j<w2){
        //     int cnt = 0;
        //     while(word1[i]==word2[j]){
        //         if(word1[i]==word2[j]){
        //             i++;
        //             j++;
        //             cnt++;
        //         }
        //     }
        // }
        
        
        
    }
};