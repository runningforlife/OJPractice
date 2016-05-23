/**
 * Reverse digits of an integer(for signed).
 */

class Solution{
private:
    int sign = 1;
    //stack<int> digits;
public:
    int reverse(int x){
        if(x == 0) return 0;

        sign = x > 0 ? 1 : -1;
        if(x < 0) x *= (-1);

        long long reverVal = 0;
        while(x > 0){
            reverVal *= 10;
            reverVal += (x%10);
            x /= 10;
        }

        reverVal *= sign;

        if(reverVal > INT_MAX || reverVal < INT_MIN)
            return 0;

        return (int)reverVal;
    }
};
