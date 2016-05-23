#include<iostream>
#include<vector>
using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))

class Solution{
public:
    int rob(vector<int>& nums){
        int best = 0, prev_best = 0;

        for(int i = 0; i < nums.size(); ++i){
            int temp = best;
            best = MAX(best,prev_best+nums[i]);
            prev_best = temp;
        }

        return best;
    }
};


int main(){
    vector<int> vi;

    int in;
    while(1){
        cin >> in;
        if(in < 0) break;
        vi.push_back(in);
    }

    Solution s;
    cout << s.rob(vi);

    return 0;
}
