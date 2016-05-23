/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 */

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int newSize = nums.size();
        int current = nums[0];
        int currentIndex = 1;

        for(int i = 1; i < nums.size(); ++i){
            if(current == nums[i]){
                --newSize;
            }else{
                current = nums[i];
                nums[currentIndex++] = current;
            }
        }

        return newSize;
    }
};
