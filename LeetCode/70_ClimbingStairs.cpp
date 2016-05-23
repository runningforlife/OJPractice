/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 *In how many distinct ways can you climb to the top?
 */
class Solution{
public:
    int climbStairs(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        int fib[2];
        fib[0] = 1;
        fib[1] = 2;

        for(int i = 3; i <= n; ++i){
            int temp = fib[1];
            fib[1] = fib[0] + fib[1];
            fib[0] = temp;
        }

        return fib[1];
    }
};
