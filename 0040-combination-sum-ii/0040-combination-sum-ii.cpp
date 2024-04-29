class Solution {
public:

    void addCombination(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& arr, int target, int sum, int ind) {
        if(sum >= target || ind >= candidates.size()) {
            if(sum == target) {
                ans.push_back(arr);
            }
            return;
        }
        arr.push_back(candidates[ind]);
        addCombination(ans, candidates, arr, target, sum+candidates[ind], ind +1);
        arr.pop_back();
        while(ind+1 < candidates.size() && candidates[ind] == candidates[ind+1]) {
            ind++;
        }
        addCombination(ans, candidates, arr, target, sum, ind +1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        addCombination(ans, candidates, arr, target, 0, 0);
        return ans;
    }
};