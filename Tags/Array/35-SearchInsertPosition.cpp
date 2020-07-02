// https://leetcode.com/problems/search-insert-position/
// keyword: binary serach


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            target < nums[mid] ? hi = mid : lo = mid + 1;
        }
        if (lo == 0) {
            return 0;
        }
        if (target == nums[lo - 1])
            return lo - 1;
        else
            return lo;
    }
};
