class Solution {
public:

    void createSet(vector<vector<int>>& ans, vector<int>& nums, vector<int> arr, int i, int n) {
        if(i >= n) {
            ans.push_back(arr);
            return;
        }
        createSet(ans, nums, arr, i+1, n);
        arr.push_back(nums[i]);
        createSet(ans, nums, arr, i+1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<vector<int>> ans;
        vector<int> arr;
        createSet(ans, nums, arr, i, n);
        return ans;
    }
};