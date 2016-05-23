/**
 * Write a program to check whether a given number is an ugly number
 */

class Solution{
    bool isUgly(int num){
        if(num <= 0) return false;
        if(num <= 5) return true;
        //if(num%2 == 1) return false;

        int primeFactors[3] ={2,3,5};
        bool isRun = false;
        while(num != 1){
            for(int i = 0; i < 3; ++i){
                if(num%primeFactors[i] == 0){
                    num /=primeFactors[i];
                    isRun = true;
                }
            }
            if(!isRun) return false;
            isRun = false;
        }
        return true;
    }
};
