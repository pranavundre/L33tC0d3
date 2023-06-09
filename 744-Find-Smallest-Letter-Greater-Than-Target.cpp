class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size(), l = 0, r = n-1;
        if(letters[r] <= target) return letters[0];
        while(l < r){
            int mid = (l+r)>>1;
            if(letters[mid] > target) r = mid;
            else l = mid+1;
        }
        return letters[l];
    }
};
