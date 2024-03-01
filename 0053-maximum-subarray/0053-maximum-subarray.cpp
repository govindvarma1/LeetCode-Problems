class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, n= nums.size();
        int temp = 0;
        for(int i=0; i<n;i++) {
            temp += nums[i];
            ans = max(ans, temp);
            if(temp < 0) {
                temp = 0;
            }     
        }
        return ans;
    }
};