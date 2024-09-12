class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int ind  = n-1;
        while(ind>=0) {
            if(digits[ind] == 9) {
                digits[ind] = 0;
                ind--;
            } else {
                digits[ind] += 1;
                return digits;
            }
        }   
        digits.insert(digits.begin(), 1);
        return digits;
    }
};