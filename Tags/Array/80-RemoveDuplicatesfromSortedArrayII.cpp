// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// My Solution, use stl functions 
// But the erase function in vector may bring low efficiency, O(n^2) in worst case
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt > 2) {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
        return nums.size();
    }
};

// A more subtle solution, use the property that the array is sorted,
// Only consider the nums[i - 2] and num, i is the place which is ready to be covered 
// O(n) complexity
// we can see num as a fast pointer and nums[i - 2] is a slow pointer, nums[i] is ready to be covered

// this solution can be easily applied to the circumstances that allow k dupilicates
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
