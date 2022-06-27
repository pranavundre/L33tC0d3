class Solution {
public:
    int minPartitions(string n) {
        string str;
        int ret = 0;
        for(int i = 0; i < n.length(); i++){
            str = n.at(i);
            ret = max(stoi(str), ret);
        }
        return ret;
    }
};