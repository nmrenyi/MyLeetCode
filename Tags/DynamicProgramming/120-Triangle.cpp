// https://leetcode.com/problems/triangle/submissions/
// keyword: dynamic programming

// The little trick here is to make use of the original vector<vector<int>> as dp array so that we only use O(1) extra space.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
            }
            triangle[i][triangle[i].size() - 1] = triangle[i - 1][triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
        }
        
        int minimal = INT_MAX;
        for (int x: triangle[triangle.size() - 1]) {
            if (x < minimal)
                minimal = x;
        }
        return minimal;
    }
};

