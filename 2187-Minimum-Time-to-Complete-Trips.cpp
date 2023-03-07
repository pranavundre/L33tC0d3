class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int l = 0, h = 1e14, m;
        while(h > l){
            m = (l + h) >> 1;
            long long int trips = 0;
            for(int i = 0; i < time.size(); i++) trips += m/time[i];
            if(trips >= totalTrips) h = m;
            else l = m+1;
        }
        return h;
    }
};
