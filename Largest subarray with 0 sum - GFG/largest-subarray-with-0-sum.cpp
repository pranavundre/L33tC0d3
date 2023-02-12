//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> mp;
        int i = 0, sum = 0, maxl = 0;
        while(i < n){
            sum+=A[i];
            if(sum==0) maxl = i + 1;
            else{
                if(mp.find(sum) == mp.end()) mp[sum] = i;
                else maxl = max(maxl, i - mp[sum]);
            }
            i++;
        }
        return maxl;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends