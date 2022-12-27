//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void sums(int ind, vector<int> &ds, vector<int> &ret, vector<int> &arr, int N){
        if(ind == N){
            int sum = 0;
            for(auto it : ds) sum = sum + it;
            ret.push_back(sum);
            return;
        }
        ds.push_back(arr[ind]);
        sums(ind+1, ds, ret,  arr, N);
        
        ds.pop_back();
        sums(ind+1, ds, ret, arr, N);
    }
    
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ds;
        vector<int> ret;
        sums(0, ds, ret, arr, N);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends