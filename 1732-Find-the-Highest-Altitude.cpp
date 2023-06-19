class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxH = 0, currH = 0;
        for(int i = 0; i < gain.size(); i++) maxH = max(maxH, currH = gain[i] + currH);
        return maxH;
    }
};
