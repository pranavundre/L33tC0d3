class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swap = 0;
        
        if(nums.size() == 2){
            swap = nums[0];
            nums[0] = nums[1];
            nums[1] = swap;
        }
        
        if(nums.size() > 2){
            for(int i = nums.size()-2; i >= 0; i--){
                if(nums[i] < nums[i+1]){
                    sort(nums.begin() + i + 1, nums.end());
                    for(int j = i+1; j < nums.size(); j++){
                        if(nums[j] > nums[i]){
                            swap = nums[i];
                            nums[i] = nums[j];
                            nums[j] = swap;
                            swap = 1;
                            break;
                        }
                    }
                    break;
                }
            }
            if(!swap){
                // if(nums[0]<nums[1] && nums[1]>nums[2] && nums[0]<nums[2]){
                //     int temp = nums[nums.size()-1];
                //     for(int j = nums.size()-1; j > 0; j--){
                //         nums[j] = nums[j-1];
                //     }
                //     nums[0] = temp;
                // }
                // else
                    sort(nums.begin(), nums.end());

            }
        }
    }
};


// 7, 6, 4, 8, 9
// 
// 46789
// 46798
// 46879
// 46897
// 46978
// 46987
// 47689
// 47698
// 47869
// 47896
// 47968
// 47986 –> 47689 –> 48679
// 
// 
// 
// 
// 















