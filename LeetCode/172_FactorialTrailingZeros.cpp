/**
 * Given an integer n, return the number of trailing zeroes in n!.
 */

class Solution{
public:
    int trailingZeroes(int n){
        if(n < 5) return 0;

        // determine whether n is the power of 5
        int zeros = 0;

        while(n > 1){
            zeros += (n /= 5);
        }

        return zeros;
    }
};
