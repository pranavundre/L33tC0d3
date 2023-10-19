class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        int n1 = s.size(), n2 = t.size();

        for(int i = 0; i < n1; i++)
            if(s[i] == '#') { if(!stk1.empty()) stk1.pop(); }
            else stk1.push(s[i]);

        for(int i = 0; i < n2; i++)
            if(t[i] == '#') { if(!stk2.empty()) stk2.pop(); }
            else stk2.push(t[i]);

        if(stk1.size() != stk2.size()) return false;
        while(!stk1.empty()){
            if(stk1.top() != stk2.top()) return false;
            stk1.pop();
            stk2.pop();
        }
        return true;
    }
};
