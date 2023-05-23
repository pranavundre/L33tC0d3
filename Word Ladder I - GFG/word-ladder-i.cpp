//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<string> q;
        set<string> words(wordList.begin(), wordList.end());
        if(!words.count(targetWord)) return 0;
        q.push(startWord);
        int n = startWord.size(), lvl = 1;
        while (!q.empty()) {
            int size = q.size();
            lvl++;
            string mod;
            while (size--) {
                string temp = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 26; j++) {
                        mod = temp.substr(0, i) + char('a' + j) + temp.substr(i + 1);
                        if (mod.compare(targetWord) == 0) return lvl;
                        if (mod.compare(temp) != 0 && words.count(mod)) {
                            words.erase(mod);
                            q.push(mod);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends