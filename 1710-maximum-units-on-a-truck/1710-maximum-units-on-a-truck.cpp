bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[1]>v2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        int maxUnits = 0;
        for(int i = 0; i < boxTypes.size(); i++){
            if(truckSize == 0)
                return maxUnits;
            if(boxTypes[i][0] < truckSize){
                truckSize -= boxTypes[i][0];
                maxUnits += boxTypes[i][0] * boxTypes[i][1];
            }else{
                maxUnits += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return maxUnits;
    }
};