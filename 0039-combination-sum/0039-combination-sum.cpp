class Solution {
public:

    void addCombinations(vector<vector<int>>& ans, vector<int>& candidates, vector<int> arr, int target, int ind, int sum) {
        if(sum >= target || ind >= candidates.size()) {
            if(sum == target) {
                ans.push_back(arr);
            }
            return;
        }
        addCombinations(ans, candidates, arr, target, ind + 1, sum);
        arr.push_back(candidates[ind]);
        addCombinations(ans, candidates, arr, target, ind, sum + candidates[ind]);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        addCombinations(ans, candidates, arr, target, 0, 0);
        return ans;
    }
};