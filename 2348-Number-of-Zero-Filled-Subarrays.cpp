class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = nums[i]==0 ? temp+1 : 0;
            count += temp;
        }
        return count;
    }
};

// Shortened Code with the same approach

// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long count = 0, temp = 0;
//         for(auto n : nums)
//             if(n==0) count += ++temp;
//             else temp = 0;
//         return count;
//     }
// };
