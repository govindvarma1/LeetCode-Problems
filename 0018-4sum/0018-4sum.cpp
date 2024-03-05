class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n-3; i++) {
                for(int j=i+1; j<n-2; j++) {
                    int l=j+1, r=n-1;
                    long long i_sum = nums[i] + nums[j];
                        while(l<r) {
                            long long int total = nums[l] + nums[r];
                            if(total + i_sum == target) {
                                ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                                while(l<r && nums[l] == nums[l+1]) {
                                    l++;
                                }
                                while(l<r && nums[r] == nums[r-1]) {
                                    r--;
                                }
                                l++; r--;
                            } else if (total + i_sum<target) {
                                l++;
                            } else {
                                r--;
                            }
                        }
                        while(j<n-2 && nums[j]==nums[j+1]) {
                            j++;
                        }
                    
                }
                while(i<n-3 && nums[i] == nums[i+1]) {
                    i++;
                }
        }
        return ans;
    }
};