class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                maxi = max(maxi, cnt);
                cnt =0;
            } else {
                cnt++;
            }
        }    
        return max(maxi, cnt);
    }
};