class Solution {
public:

    void addCombinations(vector<vector<int>>& ans, vector<int>& candidates, vector<int> arr, int target, int ind, int sum, int n) {
        if(sum >= target || ind >= n) {
            if(sum == target) {
                ans.push_back(arr);
            }
            return;
        }
        addCombinations(ans, candidates, arr, target, ind + 1, sum, n);
        arr.push_back(candidates[ind]);
        addCombinations(ans, candidates, arr, target, ind, sum + candidates[ind], n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int sum = 0, ind = 0, n = candidates.size();
        addCombinations(ans, candidates, arr, target, ind, sum, n);
        return ans;
    }
};