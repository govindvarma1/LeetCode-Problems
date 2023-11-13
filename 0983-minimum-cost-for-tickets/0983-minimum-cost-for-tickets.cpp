class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,vector<int>& dp, int &n, int i) {
        if(i==n) {
            return 0;
        } 
        if(dp[i]!=-1) {
            return dp[i];
        }
        int next_seven = upper_bound(days.begin(), days.end(), days[i]+6)-days.begin();
        int next_thirty = upper_bound(days.begin(), days.end(), days[i]+29)-days.begin();
        int one = costs[0] + solve(days, costs, dp, n, i+1);
        int seven = costs[1] + solve(days, costs, dp, n, next_seven);
        int thirty = costs[2] + solve(days, costs, dp, n, next_thirty);
        return dp[i] = min(one, min(seven, thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs,dp, n, 0);        
    }
};