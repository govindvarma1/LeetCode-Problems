class Solution {
public:

    void dfs(vector<vector<int>> &adjList,vector<vector<int>> &ans, vector<int> &vis, vector<int> & disc, vector<int> &low, int node, int parent, int &timer) {
        vis[node] = 1;
        low[node] = disc[node] = timer++;
        for(int nbr: adjList[node]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                dfs(adjList, ans, vis, disc, low, nbr, node, timer);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] > disc[node]) {
                    ans.push_back({nbr, node});
                }
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> disc(n, -1);
        vector<int> vis(n, 0);
        vector<int> low(n, -1);
        vector<vector<int>> ans;
        int timer = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(adjList, ans, vis, disc, low, i, -1, timer);
            }
        }
        return ans;
    }
};