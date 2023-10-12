/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountain) {
        int n = mountain.length();
        int l = 0, r = n-1, peak = -1;

        // finding the index of peak
        while(l <= r && peak == -1){
            int mid = (l+r)/2;
            int prev = mid == 0 ? -1 : mountain.get(mid-1);
            int curr = mountain.get(mid);
            int next = mid == n-1 ? -1 : mountain.get(mid+1);
            if((curr > next) && (curr > prev)) peak = mid;
            else if(curr < next) l = mid + 1;
            else if(curr > next) r = mid - 1;
        }
        peak = peak == -1 ? l : peak;
        if(mountain.get(peak) == target) return peak;

        // searching on the left of the peak
        l = 0, r = peak-1;
        while(l <= r){
            int mid = (l+r)/2;
            int curr = mountain.get(mid);
            if(curr == target) return mid;
            if(curr < target) l = mid + 1;
            if(curr > target) r = mid - 1;
        }
        if(l >= 0 && mountain.get(l) == target) return l;

        // searching on the right of the peak
        l = peak+1, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            int curr = mountain.get(mid);
            if(curr == target) return mid;
            if(curr < target) r = mid - 1;
            if(curr > target) l = mid + 1;
        }
        if(l < n && mountain.get(l) == target) return l;

        return -1;
    }
};
