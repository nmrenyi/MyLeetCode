// https://leetcode.com/problems/remove-element/
// take care of some corner cases, such as empty vector and all elements needs to be removed
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int end_p = nums.size() - 1;
        for (int i = 0; i < end_p; i++) {
            if (nums[i] == val) {
                for (; end_p > i && nums[end_p] == val; end_p--);
                if (end_p == 0)
                    return 0;
                swap(nums[i], nums[end_p]);
                end_p--;
            }
        }
        if (nums[end_p] == val) {
            end_p--;
        }

        return end_p + 1;
    }
    
};


// A simpler solution in java
/*
public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
*/
