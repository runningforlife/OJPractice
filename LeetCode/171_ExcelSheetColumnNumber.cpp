/**
 * Given a column title as appear in an Excel sheet, return its corresponding column number
 */

class Solution
public:
    int titleToNumber(string s){
        if(s.empty()) return 0;

        int ret = 0;
        for(int i = 0; i < s.size(); ++i){
            ret *= 26;
            ret += (s[i] - 'A' + 1);
        }

        return ret;
    }
};
