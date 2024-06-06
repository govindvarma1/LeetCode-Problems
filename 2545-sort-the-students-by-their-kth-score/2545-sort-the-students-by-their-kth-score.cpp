class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        vector<vector<int>> arr(n, vector<int>(2));
        for(int i=0; i<n; i++) {
            vector<int> temp = {score[i][k], i};
            arr[i] = temp;
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(score[arr[i][1]]);
        }
        return ans;
    }
};