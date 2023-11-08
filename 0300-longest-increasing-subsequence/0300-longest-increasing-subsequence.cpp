class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int length = 1;
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i] > temp[length-1]) {
                temp.push_back(nums[i]);
                length++;
            }
             else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return length;
    }
};