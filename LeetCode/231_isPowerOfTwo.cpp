/**
 * determine whether an integer is power of two
 */

class Solution{
public:
    bool isPowerOfTwo(int n){
        if(n <= 0) return false;
N
        return (n&(n-1)) == 0
    }
};
