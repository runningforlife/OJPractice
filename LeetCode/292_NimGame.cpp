/*
There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.
The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game.
Write a function to determine whether you can win the game given the number of stones in the heap
*/
#include<cstdio>
class Solution{

public:
    bool canWinNim(int n){
        return n%4 != 0;
    }
};
int main()
{
    Solution s;
    if(s.canWinNim(3))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
