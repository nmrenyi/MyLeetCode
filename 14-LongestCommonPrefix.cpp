// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return string("");
        string result = string("");
        int length = 0x3f3f3f3f;
        for (string s:strs) {
            if (length > s.size())
                length = s.size();
        }
        
        for (int i = 0; i < length; i++) {
            char now = strs[0][i];
            bool ok = true;
            for (string s: strs) {
                if (now != s[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
            string now_res;
            now_res.push_back(now);
            result.append(now_res);
        }
        return result;
    }
};
