/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
   For example,
   s = "anagram", t = "nagaram", return true.
   s = "rat", t = "car", return false
*/
class Solution{
public:
    bool isAnagram(string s,string t){
        if(s.size() != t.size()) return false;

        int *sHash = new int[27]();
        int *tHash = new int[27]();

        for(string::iterator it = s.begin(),it1 = t.begin(); it != s.end(); ++it,++it1){
            ++sHash[*it - 'a'];
            ++tHash[*it1 - 'a'];
        }

        for(int i = 0; i < 26; ++i)
            if(sHash[i] != tHash[i])
                return false;

        return true;
    }
};
