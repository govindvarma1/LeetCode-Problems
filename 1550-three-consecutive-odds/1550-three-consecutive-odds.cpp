class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]%2 == 1) {
                if(odd == 2) {
                    return true;
                } else {
                    odd++;
                }
            } else {
                odd = 0;
            }
        }   
        return false;

    }
};