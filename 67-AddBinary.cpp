// https://leetcode.com/problems/add-binary/
// A little bit boring and sophisticated!

class Solution {
public:
    string addBinary(string a, string b) {
        string l = a.size() > b.size() ? a : b;
        string s = a.size() <= b.size() ? a : b;
        string result = string("");
        int length = s.size();
        int carry = 0;
        for (int i = 0; i < length; i++) {
            int a = l[l.size() - 1 - i] - '0';
            int b = s[s.size() - 1 - i] - '0';
            int tmp_sum = a + b + carry;
            carry = tmp_sum >= 2 ? 1 : 0;
            if (tmp_sum % 2 == 0) {
                result.insert(0, "0");
            } else {
                result.insert(0, "1");
            }
        }
        if (carry == 0) {
            result.insert(0, l.substr(0, l.size() - s.size()));
            return result;
        } 
        else {
            for (int i = l.size() - s.size() - 1; i >= 0; i--) {
                if (l[i] == '0') {
                    result.insert(0, "1");
                    result.insert(0, l.substr(0, i));
                    break;
                } else {
                    result.insert(0, "0");
                    if (i == 0) {
                        result.insert(0, "1");
                    }
                }
            }
            if (l.size() == s.size()) {
                result.insert(0, "1");
            }
            
            return result;
        }
    }
};
