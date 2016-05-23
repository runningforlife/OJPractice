/**
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 */

 class Solution{
 private:
    const int foundNumber = 1;
 public:
    int countOnes(int n){
        int cnt = 0;
        while(n > 0){
            if(n%10 == foundNumber) ++cnt;
            n /= 10;
        }
        return cnt;
    }

    int countDigitOne(int n){
        if(n < 1) return 0;
        else if(n < 10) return 1;

        int numberOfOnes = 1;
        for(int i = 10; i <= n; ++i){
            numberOfOnes += countOnes(i);
        }

        return numberOfOnes;
    }
 };
