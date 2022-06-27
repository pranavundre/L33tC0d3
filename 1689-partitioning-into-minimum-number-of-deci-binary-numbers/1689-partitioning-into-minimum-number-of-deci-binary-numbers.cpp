class Solution {
public:
    int minPartitions(string n) {
        int x;
        set<int> st;
        string str;
        for(int i = 0; i < n.length(); i++){
            str = n.at(i);
            x = stoi(str);
            st.insert(x);
        }
        auto it = st.rbegin();
        return *it;
    }
};