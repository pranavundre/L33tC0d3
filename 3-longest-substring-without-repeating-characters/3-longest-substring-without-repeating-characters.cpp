class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256+1] = {0};
        int m = 0;
        int l = 0, r = 0;
        while(r<s.length())
        {
            ++count[s[r]];
            while(count[s[r]] > 1){
                --count[s[l]];  
                ++l;
            }
            
            m = max(m, r-l+1);
            ++r;
        }
        return m;
        
        // int i = 0, max = 1;
        // bool rep = false;
        // if(s.length()==0 || s.length()==1)
        //     return s.length();
        // else
        //     while(i<s.length()-1){
        //         int l = 1;
        //         for(int j = i+1; j<s.length(); j++){
        //             if(s[i]==s[j]){
        //                 rep = true;
        //                 l = 0;
        //                 if((j-i)>max)
        //                     max = j-i;
        //                 break;
        //             }
        //             // else if(l==1 && j==(s.length()-1))
        //             //     return (s.length()-i);
        //         }
        //         i++;
        //     }
        // if(!rep)
        //     return s.length();
        // return max;
    }
};