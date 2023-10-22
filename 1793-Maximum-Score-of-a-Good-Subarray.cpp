class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while (left > 0 || right < nums.size() - 1) {
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
                right++;
            } else {
                left--;
            }
            min_val = std::min(min_val, std::min(nums[left], nums[right]));
            max_score = std::max(max_score, min_val * (right - left + 1));
        }
        
        return max_score;

        // need to try later

        // stack<pair<int, int>> stk;
        // int n = nums.size(), ans = 0;
        // for(int i = 0; i < n; i++){
        //     int r = i, l;
        //     while(!stk.empty() && stk.top().first > nums[i]){
        //         auto p = stk.top();
        //         stk.pop();
        //         l = stk.empty() ? -1 : stk.top().second;
        //         cout<<r<<" "<<l<<" ";
        //         int len = (r <= k && l >= k) ? r-l-1 : 0, temp = p.first*len;
        //         r = p.second;
        //         ans = max(ans, temp);
        //         cout<<ans<<endl;
        //     }
        //     if(!stk.empty() && stk.top().first == nums[i]) stk.top().second = i;
        //     else stk.push({nums[i], i});
        // }
        // int r = n-1, l;
        // while(!stk.empty()){
        //     auto p = stk.top();
        //     stk.pop();
        //     l = stk.empty() ? -1 : stk.top().second;
        //     int temp =  r >= k ? p.first*(r - l - 1) : -1;
        //     r = p.second;
        //     ans = max(ans, temp);
        // }
        // return ans;
    }
};
