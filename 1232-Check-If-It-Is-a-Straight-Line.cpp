class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int xdiff = coordinates[1][0]-coordinates[0][0];
        int ydiff = coordinates[1][1]-coordinates[0][1];
        float slope;
        if(xdiff == 0) slope = INT_MAX;
        else slope = static_cast<float>(ydiff)/xdiff;
        for(int i = 2; i < coordinates.size(); i++){
            xdiff = coordinates[i][0]-coordinates[0][0];
            ydiff = coordinates[i][1]-coordinates[0][1];
            float nslope;
            if(xdiff == 0) nslope = INT_MAX;
            else nslope = static_cast<float>(ydiff)/xdiff;
            if(nslope!=slope) return false;
        }
        return true;
    }
};
