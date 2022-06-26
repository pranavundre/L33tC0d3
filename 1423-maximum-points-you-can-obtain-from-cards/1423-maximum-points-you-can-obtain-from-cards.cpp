class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> back;
        vector<int> front;
        int max, n = cardPoints.size();
        
        back.push_back(cardPoints[n-1]);
        front.push_back(cardPoints[0]);
        
        for(int i = 1; i < k; i++){
            back.push_back(back[i-1] + cardPoints[n-i-1]);
            front.push_back(front[i-1] + cardPoints[i]);
        }
        
        max = back[k-1]>front[k-1] ? back[k-1] : front[k-1];
        
        for(int i = 0; i < k-1; i++){
            int x = back[i] + front[k-i-2];
            max = x>max ? x:max;
        }
        
        return max;
    }
};