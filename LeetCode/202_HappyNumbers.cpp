/**
 * check whether a number is a happy number
 */
#include<map>
#include<iostream>
using namespace std;

class Solution{
public:
    int getNewNum(int n){
        int ret = 0;
        while(n != 0){
            int tmp = n%10;
            ret +=(tmp*tmp);
            n /= 10;
        }

        return ret;
    }
    bool isHappy(int n){
        if(n <= 0) return false;
        if(n == 1) return true;

        map<int,int> numM;
        map<int,int>::iterator it;
        numM[n] = 0;
        int numCount = 0;
        while(1){
            n = getNewNum(n);
            if(n == 1)
                return true;
            it = numM.find(n);
            if(it == numM.end()){
                numM[n] = ++numCount;
            }else
                return false;
        }
    }
};

int main(){
    Solution s;
    cout << s.isHappy(7);

    return 0;
}
