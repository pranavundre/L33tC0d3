class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = nums[0];
        for(auto i : nums){
            sum+=i;
            maxsum = max(sum, maxsum);
            if(sum<0) sum = 0;
        }
        return maxsum;
    }
};




// int maxsum = nums[0];
// for(int i = 0; i < nums.size(); i++){
//     int sum = 0;
//     for(int j = i; j < nums.size(); j++){
//         sum += nums[j];
//         maxsum = max(maxsum, sum);
//     }
// }