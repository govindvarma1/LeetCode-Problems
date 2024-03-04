class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<=n-2; i++) {
            if(i==0 || (i>0 && nums[i] != nums[i-1])) {
                int l = i+1, r = n-1;
                while(l<r) {
                    int tot =  nums[l] + nums[r];
                    if(tot+nums[i] == 0) {
                        vector<int> triplet = {nums[i], nums[l], nums[r]};
                        ans.push_back(triplet);
                        while(l<r && nums[l] == nums[l+1]) {
                            l++;
                        }
                        while(l<r && nums[r] == nums[r-1]) {
                            r--;
                        }
                        l++; r--;
                    } else if(tot< -1*nums[i]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }        
        return ans;
    }
};