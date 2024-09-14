class Solution {
public:

    int maxElement(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] >= ans) {
                ans = nums[i];
            }
        }
        return ans;
    }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxEle = maxElement(nums);
        int temp_len = 0, len = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] == maxEle) {
                temp_len++;
            } else {
                len = max(len, temp_len);
                temp_len = 0;
            }
        }        
        return max(len, temp_len);
    }
};