// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/

// keyword: binary serach

class Solution {
public:
    int binarySearch(vector<int> nums, int& lo, int& hi, int target) {
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            target < nums[mi] ? hi = mi : lo = mi + 1;
        }
        return lo - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        binarySearch(nums, lo, hi, target);
        if (lo == 0) {
            return vector<int>({-1, -1});
        } else {
            if (target == nums[lo - 1]) {
                int end = lo - 1;
                lo = 0;
                hi = nums.size();
                binarySearch(nums, lo, hi, target - 1);
                return vector<int>({lo, end});
                
            } else {
                return vector<int>({-1, -1});
            }
        }
    }
};
