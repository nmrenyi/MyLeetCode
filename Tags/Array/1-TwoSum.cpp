// https://leetcode.com/problems/two-sum/
// My Implementation
class Solution {
public:
    // an O(n) solution
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> mySet;  // unordered set use hashtable inside, set use RB tree in side
        for (int x : nums) {
            mySet.insert(x);
        }
        bool find = false;
        int index1 = 0, index2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (find)
                break;
            auto it = mySet.find(target - nums[i]);
            if (it != mySet.end()) {
                index1 = i;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == target - nums[i]) {
                        index2 = j;
                        find = true;
                        break;
                    }
                }
            }
        }
        vector<int> result;
        result.push_back(index1);
        result.push_back(index2);
        return result;
    }
};

