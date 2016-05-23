/**
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ¡Ü j), inclusive.
 */

class Solution{
public:
    int countRangeSum(vector<int>& nums,int lower, int upper){
        if(lower > upper || nums.empty()) return 0;

        vector<int> prefixSum = nums;

        int numberOfSums = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= lower && nums[i] <= upper){
                ++numberOfSums;
            }
        }

        for(int i = 1; i < nums.size(); ++i){
            prefixSum[i] += prefixSum[i-1];
            if(prefixSum[i] >= lower && prefixSum[i] <= upper)
                ++numberOfSums;
        }

        return numberOfSums;
    }
};
