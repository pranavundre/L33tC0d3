//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        
        vector<vector<string>> res;
        vector<string> temp;
        temp.push_back(beginWord);
        
        set<string> words(wordList.begin(), wordList.end());
                
        q.push(temp);
        
        words.erase(beginWord);
        
        int n = beginWord.size();
        int lvl = -1;
        
        while (!q.empty()) {
            int size = q.size();
            lvl++;
            string mod;
            vector<string> del;
            
            while (size--) {
                
                vector<string> lastVec = q.front();
                string last = lastVec[lvl];
                q.pop();
                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 26; j++) {
                        mod = last.substr(0, i) + char('a' + j) + last.substr(i + 1);

                        if(words.count(mod)){

                            lastVec.emplace_back(mod);
                            if (mod.compare(endWord) == 0) res.emplace_back(lastVec);

                            else if (mod.compare(last)) {
                                q.push(lastVec);
                                lastVec.pop_back();
                                del.emplace_back(mod);
                            }
                        }
                    }
                }
            }
            if(res.size()) break;
            for(string s : del) words.erase(s);
        }

        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends