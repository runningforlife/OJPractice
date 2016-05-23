/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

class Solution{
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        if(x%10 == 0) return false;

        int n = 0;
        while(x > 0){
            n *= 10;
            n += (x%10);
            if(n == x || n == x/10)
                return true;
            x /= 10;
        }

        return false;
    }
};
