class Solution {
public:

    int solve(vector<int>& nums, int k) {
        if(k <= 0) {
            return 0;
        }
        int left = 0, right = 0, ans = 0;
        int n = nums.size(), diff = 0;
        map<int, int> mpp;
        while(right < n) {
            if(mpp[nums[right]] == 0) {
                diff++;
            }
            mpp[nums[right]]++;
            while(diff > k) {
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) {
                    diff--;
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k)  - solve(nums, k-1) ;
    }
};