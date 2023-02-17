//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N) {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> ret;
        int i = 0;
        int c = 0;
        while(i < coins.size()){
            c = N/coins[i];
            if(c==0){
                i++;
                continue;
            }
            N -= (N/coins[i])*(coins[i]);
            // cout<<c<<" "<<coins[i]<<" "<<N<<endl;
            for(int j = 0; j < c; j++){
                ret.emplace_back(coins[i]);
            }
            i++;
        }
        return ret;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends