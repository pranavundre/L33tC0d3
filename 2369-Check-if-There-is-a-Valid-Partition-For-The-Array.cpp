class Solution {
public:
int dp[100005];
int solve(int j,vector<int>&nums){
    if(j==nums.size()){
        return 1;
    }
    if(dp[j]!=-1)
    return dp[j];
    int c=0;
       if(j+1<nums.size()){
           if(nums[j]==nums[j+1])
             c=c|solve(j+2,nums);
       }
       if(j+2<nums.size()){
           if(nums[j]==nums[j+1]&&nums[j]==nums[j+2]){
               c=c|solve(j+3,nums);
           }
           if(nums[j]+1==nums[j+1]&&nums[j+1]+1==nums[j+2]){
                c=c|solve(j+3,nums);
           }
       }
       return dp[j]= c;
}
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
