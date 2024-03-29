//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool sortvector(const vector<int> &a,  const vector<int> &b){
        return a[1] < b[1];
    }
    
    int maxMeetings(int start[], int end[], int n){
        vector<vector<int>> meetings;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            // temp.push_back(i+1);
            meetings.push_back(temp);
        }
        
        sort(meetings.begin(), meetings.end(), sortvector);
        
        int maxMeet = 1;
        int j = 0;
        for(int i = 1; i < n; i++){
            if(meetings[i][0] > meetings[j][1]){
                maxMeet++;
                j = i;
            }
        }
        return maxMeet;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends