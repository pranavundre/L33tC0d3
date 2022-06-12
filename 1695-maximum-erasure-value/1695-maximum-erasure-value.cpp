class Solution {
public:
    
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int l=0, r=0; //define left and right pointers for sliding windows approach
        
        vector<int> sum_arr; //sum_arr stores sum of element of nums at index i;
        sum_arr.push_back(0); //initially l and r at 0 so to consider element at index 0 we need to take 0 at index 0
        
        int sum=0, score=nums[0];
        for(auto it:nums) //storing sum into sum_arr
        {
            sum += it;
            sum_arr.push_back(sum);
        }
        
        unordered_map<int, int> mp; //stores element and their index
        
        while(r<nums.size()) //iterate till r pointer is lesser than nums' size 
        {
            if(mp.find(nums[r]) != mp.end()) l=max(l, mp[nums[r]]+1); //when repeated element come we move left pointer of the right of repeated element
            mp[nums[r]] = r; //assigning index to the element
            score = max(score, sum_arr[r+1]-sum_arr[l]); //get max score
            r++; //move r by 1 
        }
        return score;
    }
    
    
    

    
//     vector<int> b;
    
//     bool isInArray(int ele){
//         for(int i : b){
//             if(i == ele){
//                 return true;
//             }
//         }
//         return false;
//     }
    
//     int maximumUniqueSubarray(vector<int>& nums) {
//         unsigned long int max = 0;
//         for(int i = 0; i < nums.size(); i++){   //i=1
//             b.push_back(nums[i]);   //b{4}
//             unsigned long int sum = nums[i];
//             for(int j = i+1; j < nums.size(); j++){ //j=2
//                 if(isInArray(nums[j])){
//                     b.clear();
//                     break;
//                 }
//                 else if(j+1==nums.size()){
//                     b.push_back(nums[j]);
//                     sum += nums[j];
//                     b.clear();
//                     break;
//                 }
//                 else{
//                     b.push_back(nums[j]);   //b{4, 2}
//                     sum += nums[j];
//                 }
//             }
//             max = (sum>max) ? sum : max;
//         }
//         return max;
//     }
};