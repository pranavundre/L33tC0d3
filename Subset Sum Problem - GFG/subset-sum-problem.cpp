//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>& arr, vector<vector<int>>& dp, int index, int sum){
        if(sum == 0) return true;
        if(index == 0) return sum == arr[0];
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool notTake = solve(arr, dp, index-1, sum);
        bool take = false;
        
        if(arr[index] <= sum) take = solve(arr, dp, index-1, sum-arr[index]);
        
        return dp[index][sum] = take || notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return solve(arr, dp, n-1, sum);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends