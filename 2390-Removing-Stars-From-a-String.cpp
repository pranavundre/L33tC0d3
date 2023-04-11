class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        stack<char> stk1;
        string res = "";
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '*' && !stk.empty()) stk.pop();
            else stk.push(s[i]);
        while(!stk.empty()){
            stk1.push(stk.top());
            stk.pop();
        }
        while(!stk1.empty()){
            res += stk1.top();
            stk1.pop();
        }
        return res;
    }
};
