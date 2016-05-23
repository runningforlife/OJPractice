/**
 * Reverse bits of a given 32 bits unsigned integer.
 */
#include<cstdio>

class Solution{
    public:
    void getBits(char *str,unsigned n){
        int i = 0;
        while(n != 0){
            str[i++] = n%2;
            n /= 2;
        }
    }
    unsigned reverseBits(unsigned n){
        if(n == 0) return 0;
        char *str = new char[33]();

        getBits(str,n);
        unsigned ret = 0;
        for(int i = 0; i < 32; ++i){
            ret *= 2;
            ret += (str[i]);
        }

        return ret;
    }
};


int main()
{
    Solution s;
    printf("%u",s.reverseBits(1));
}
