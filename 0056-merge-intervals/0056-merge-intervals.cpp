class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++) {
            int end = ans.back()[1];
            if(end>=intervals[i][0] && end<=intervals[i][1]) {
                ans.back()[1] = intervals[i][1];
            } else if(intervals[i][1] > end) {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};