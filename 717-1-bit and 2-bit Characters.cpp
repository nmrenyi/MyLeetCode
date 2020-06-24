// https://nmrenyi.github.io/2020/06/24/LeetCode717/
// https://leetcode.com/problems/1-bit-and-2-bit-characters/

class Solution {
public:
    vector<int>& getNext(vector<int>& bits) {
        if (bits[0] == 1 && bits[1] == 1) {
            bits.erase(bits.begin(), bits.begin() + 2);
            return bits;
        }
        else if (bits[0] == 1 && bits[1] == 0) {
            bits.erase(bits.begin(), bits.begin() + 2);
            return bits;
        }
        else if (bits[0] == 0 && bits[1] == 0) {
            bits.erase(bits.begin(), bits.begin() + 2);
            return bits;
        }
        else {  // (bits[0] == 0 && bits[1] == 1) 
            bits.erase(bits.begin(), bits.begin() + 1);
            return bits;
        }
    }
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() >= 3) {
            return isOneBitCharacter(getNext(bits));
        }
        if (bits.size() == 1) {
            if (bits[0] == 0)
                return true;
            return false;
        }
        else {  // bits.size() == 2
            if (bits[0] == 1)  // 10, 11
                return false;
            return true;  // only 00, 01 is not possible
        }

    }
};
