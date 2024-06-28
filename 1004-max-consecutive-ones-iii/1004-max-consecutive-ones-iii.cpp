class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, zeros = 0, ans = 0;
        while(right<n) {
            if(nums[right] == 0) {
               zeros++; 
            }
            while(zeros>k) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            ans = max(right - left + 1, ans);
            right++;
        }
        return ans;
    }
};