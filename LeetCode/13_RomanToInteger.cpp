/**
 * given a roman numeral, convert it to an integer
 * hint: If a lower value symbol is before a higher value one, it is subtracted. Otherwise it is added
 */

class Solution{
public:
    int romanToInt(string s){
        if(s.empty()) return 0;

        map<char,int> mappedTable;
        mappedTable['I'] = 1,mappedTable['V'] = 5;
        mappedTable['X'] = 10,mappedTable['L'] = 50;
        mappedTable['C'] = 100,mappedTable['D'] = 500;
        mappedTable['M'] = 1000;

        int ret = 0;
        int sz = s.size();
        for(int i = 0; i < sz; ){
            if((i+1) < sz && mappedTable[s[i]] < mappedTable[s[i+1]]){
                ret += (mappedTable[s[i+1]] - mappedTable[s[i]]);
                i += 2;
            }else{
                ret += mappedTable[s[i]];
                ++i;
            }
        }

        return ret;
    }
};
