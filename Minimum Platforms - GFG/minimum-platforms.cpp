//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int findPlatform(int Arr[], int Dep[], int n){
        vector<int> arr;
        vector<int> dep;
        for(int i = 0; i < n; i++){
            arr.push_back(Arr[i]);
            dep.push_back(Dep[i]);
        }
    	sort(arr.begin(), arr.end());
    	sort(dep.begin(), dep.end());
    	
    	int a = 0, d = 0, num = 0, pf = 0;
    	
    	while(a<n && d<n){
    	    if(arr[a] <= dep[d]){
    	        pf++;
    	        a++;
    	        num = max(pf, num);
    	    }else{
    	        pf--;
    	        d++;
    	    }
    	}
    	return num;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends