class Solution {
public:

    int sum(vector<int>& arr) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }

    void addCombination(vector<vector<int>>& ans,vector<int>& arr,int n, int k, int ind) {
        if(ind>9 || arr.size() == k) {
            if(sum(arr) == n && arr.size() == k) {
                ans.push_back(arr);
            }
            return;
        }
        addCombination(ans, arr, n, k, ind+1);
        arr.push_back(ind);
        addCombination(ans, arr, n, k, ind+1);
        arr.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        addCombination(ans, arr, n, k, 1);
        return ans;        
    }
};