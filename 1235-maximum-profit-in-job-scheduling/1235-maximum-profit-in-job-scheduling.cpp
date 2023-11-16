class Solution {
public:

    int binarySearch(vector<vector<int>>&v, int val){
        int n = v.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <=  high){
            int mid = (high + low)/2;
            if(v[mid][0] >= val){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }   

    int solve(vector<vector<int>> jobs, int n) {
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            int next = binarySearch(jobs, jobs[i][1]);
            int pick = jobs[i][2] + dp[next];
            int notPick = dp[i+1];
            dp[i] = max(pick, notPick);
        } 
        return dp[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        return solve(jobs, n);
    }
};