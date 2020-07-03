// https://leetcode.com/problems/n-th-tribonacci-number/
// keyword, dynamic programming
// note: is there any faster solution in tribonacci like fibonacci?

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        int p0 = 0, p1 = 1, p2 = 1;
        for (int i = 3; i <= n; i++) {
            int now = p0 + p1 + p2;
            p0 = p1;
            p1 = p2;
            p2 = now;
        }
        return p2;
    }
};