/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

 class Solution{
 public:
    vector<int> plusOne(vector<int>& nums){
        if(digits.empty())  return digits;

        int len = digits.size();
        int carry = 1;
        //bool hasCarry = false;

        do{
            int add = digits[len-1] + carry;
            digits[--len] = add%10;
            carry = add/10;
        }while(len > 0 && carry);

        if(len == 0 && carry){
            digits.insert(digits.begin(),1);
        }

        return digits;
    }
 };
