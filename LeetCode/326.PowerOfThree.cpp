/**
 * Given an integer, write a function to determine if it is a power of three.
 */

class Solution{
public:
    bool isPowerOfThree(int n){
        if(n == 1) return true;
        else if(n > 1 && n%3 != 0) return false;

        int s = 1;
        while(s < n){
            s *= 3;
        }
        if(s == n) return true;
        else return false;
    }
};
