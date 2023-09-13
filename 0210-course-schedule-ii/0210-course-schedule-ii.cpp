class Solution {
public:

    bool detect(vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis, vector<int>& marked, int node, vector<int>& ans) {
        dfsvis[node] = 1;
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(detect(adj, vis, dfsvis, marked, it, ans)) {
                    return true;
                }
            }
            else if(dfsvis[it]) {
                return true;

            }
        }
        if(!marked[node]) {
            marked[node]=1;
            ans.push_back(node);
        }
        dfsvis[node] = 0;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);
        vector<int> marked(n, 0);
        vector<vector<int>> adj(n);
        for(auto it: prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i< n;i++) {
            if(!vis[i]) {
                if(detect(adj, vis, dfsvis, marked, i, ans)) {
                    return {};
                }
            }
        }
        return ans;
    }
};