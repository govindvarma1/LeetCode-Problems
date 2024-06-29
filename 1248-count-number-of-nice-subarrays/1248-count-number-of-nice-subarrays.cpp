class Solution {
public:
    
    int func(vector<int>& nums, int k) {
        if(k<0) {
            return 0;
        }
        int n = nums.size(), left = 0, right = 0;
        int ans = 0, odds = 0;
        while(right < n) {
            odds += nums[right]%2;
            while(odds > k) {
                odds -= nums[left]%2;
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
       return func(nums, k) - func(nums, k-1);
    }
};