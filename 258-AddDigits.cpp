// https://leetcode.com/problems/add-digits/
// https://nmrenyi.github.io/2020/06/24/LeetCode258/
class Solution {
public:
    vector<int> decomposite(int num) {
        vector<int> res;
        while (num > 0) {
            res.push_back(num % 10);
            num /= 10;
        }
        return res;
    }
    int summation(vector<int> v) {
        int sum = 0;
        for(int x : v) {
            sum += x;
        }
        return sum;
    }
    int addDigits(int num) {
        while (num >= 10) {
            vector<int> component = decomposite(num);
            num = summation(component);        
        }
        return num;
    }
    
};
