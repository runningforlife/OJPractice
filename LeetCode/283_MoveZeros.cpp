/**
 * move zeros of an array to the end of it and keep the
 * relative order of non-zeros element
 */

class Solution{
public:
    void moveZeros(vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i])  continue;
            int temp = nums[i];
            int curr = i;
            for(int j = i+1; j < nums.size(); ++j){
                if(nums[j]){
                    nums[curr] = nums[j];
                    curr = j;
                }
                nums[curr] = temp;
            }
        }
    }
};
