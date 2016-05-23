/**
 * Write a function that takes an unsigned integer and
 * returns the number of ¡¯1' bits it has (also known as the Hamming weight).
 */

class Solution{
public:
    int hammingWeight(uint32_t n){
        int ret = 0;
        while(n != 0){
            ++ret;
            n &= (n-1);
        }

        return ret;
    }
};
