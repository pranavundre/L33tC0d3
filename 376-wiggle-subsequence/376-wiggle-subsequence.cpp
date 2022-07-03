class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int inc = 1, dec = 1;
        for(int i=1; i< nums.size(); i++){
            if(nums[i] > nums[i-1]) inc = dec+1;
            else if(nums[i] < nums[i-1]) dec = inc+1;
        }
        return max(inc, dec);
        
        
        
//         if(nums.size()==1)
//             return 1;
//         if(nums.size()==2){
//             if(nums[0]!=nums[1])
//                 return 2;
//             return 0;
//         }
        
//         int c = 2;
//         int maxl = 2;
        
//         for(int i = 1; i < nums.size()-1; i++){
//             if((nums[i]-nums[i-1])^(nums[i+1]-nums[i])<0){
//                 c++;
//                 maxl = max(maxl, c);
//             }else{
//                 c=2;
//                 i--;
//             }
//         }
//         return maxl;
        
    }
};