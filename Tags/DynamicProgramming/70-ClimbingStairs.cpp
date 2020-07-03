// https://leetcode.com/problems/climbing-stairs/
// keyword: dynamic programming, fibonacci calculating
// note: many other ways of calculating fibonacci array are in the solution of leetcode
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)
            return n;
        int* way = new int[n + 1];
        way[1] = 1;
        way[2] = 2;
        for (int i = 3; i <= n; i++) {
            way[i] = way[i - 1] + way[i - 2];
        }
        int result = way[n];
        delete[] way;
        return result;
    }
};
