class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        stk.push(pushed[0]);
        int i = 0, j = 1;
        while(i<n){
            if(!stk.empty() && stk.top() == popped[i]){
                stk.pop();
                i++;
            }
            else{
                if(j == n) return false;
                else stk.push(pushed[j++]);
            }
        }
        return true;
    }
};
