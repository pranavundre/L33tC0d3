class Solution {
    public:
    static bool sortvec(const vector<int> &a, const vector<int> &b){
        return a[1] > b[1];
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> p(n);

        for(int i = 0; i < n; i++){
            p[i].push_back(nums1[i]);
            p[i].push_back(nums2[i]);
        }

        sort(p.begin(), p.end(), sortvec);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        long long sum = 0;
        long long maxVal, val;

        for(int i = 0; i < k; i++){
            pq.push(p[i]);
            sum += p[i][0];
        }

        maxVal = val = sum * p[k-1][1];

        for(int i = k; i < n; i++){
            sum += (p[i][0] - pq.top()[0]);
            pq.pop();
            pq.push(p[i]);
            val = sum*p[i][1];
            maxVal = max(maxVal, val);
        }

        return maxVal;
    }
};
