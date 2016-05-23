/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
#include<cstdio>

class Solution{
public:
    int getSum(int n){
        int s = 0;
        while(n != 0){
            s += n%10;
            n /= 10;
        }

        return s;
    }
    int addDigits(int num){
        int ret = num;
        while(ret >= 10){
            ret = getSum(ret);
        }

        return ret;
    }
};


int main()
{
    Solution s;
    printf("%d",s.addDigits(89));

    return 0;
}
