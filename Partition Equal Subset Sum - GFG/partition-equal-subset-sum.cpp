//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[]){
        int sum = 0;
        for(int i = 0; i < n; i++) sum+=arr[i];
        if(sum%2 == 1) return false;
        sum = sum/2;
        vector<int> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = curr[0] = 1;
        if(arr[0] <= sum) prev[arr[0]] = 1;
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target - arr[ind] >= 0) take = prev[target - arr[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return curr[sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends