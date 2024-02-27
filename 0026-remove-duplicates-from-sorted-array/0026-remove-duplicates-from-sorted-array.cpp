class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n && i+cnt+1<n; i++) {
            while(i+cnt+1<n && nums[i] == nums[i+cnt+1]) {
                cnt++;
            }
            if(i+cnt+1 < n) {
                nums[i+1] = nums[i+cnt+1];
            }
        }
        return n-cnt;
    }
};