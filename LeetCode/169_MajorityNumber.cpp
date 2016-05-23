/**
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than  n/2 times.
 */

class Solution{
public:
    int majorityElements(vector<int> &nums){
        map<int,int> major;
        map<int,int>::iterator it;
        for(int i = 0; i < nums.size(); ++i){
            it = major.find(nums[i]);
            if(it != major.end()){
                ++it->second;
            }
            else
                major[nums[i]] = 1;
        }

        for(it = major.begin(); it != major.end(); ++it){
            if(it->second > nums.size()/2)
                return it->first;
        }
    }
};
