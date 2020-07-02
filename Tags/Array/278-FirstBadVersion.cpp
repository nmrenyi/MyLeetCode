// https://leetcode.com/problems/first-bad-version/

// keyword: binary search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo = 1, hi = (long long)(n) + 1;
        while (lo < hi) {
            long long mi = (lo + hi) >> 1;
            if (isBadVersion(mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
