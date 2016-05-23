/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 */

class Solution{
public:
    bool containsDumplicate(vector<int> &nums){
        if(nums.size() == 0 || nums.size() == 1) return false;

        const unsigned long max = ULONG_MAX;
        const unsigned long offset = INT_MAX + 1;
        bool *hashTable = new bool[max]();
        for(int i = 0; i < nums.size(); ++i){
            unsigned long hashVal = nums[i] + offset;
            if(!hashTable[hashVal])
                hashTable[hashVal] = true;
            else
                return true;
        }
        /** TimeExceeded: for(int i = 0; i < nums.size(); ++i){
            for(int j = i+1; j < nums.size(); ++j)
                if(nums[i] == nums[j])
                    return true;
        }*/
        return false;
    }
};
