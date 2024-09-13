class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> ans;
        for(int i=1; i<n; i++) {
            arr[i] = arr[i] ^ arr[i-1];
        }
        for(int i=0; i<m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start == 0) {
                ans.push_back(arr[end]);
            } else {
                ans.push_back(arr[end] ^ arr[start-1]);
            }
        }
        return ans;
    }
};