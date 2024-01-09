class Solution {
public:

    void convertToAdjMatrix(vector<vector<int>>& graph, vector<vector<int>>& adjMatrix, int& n) {
        for(int i=0; i<n; i++) {
            int m = graph[i].size();
            for(int j=0; j<m; j++) {
                adjMatrix[i][graph[i][j]] =  1;
            }
        }
    }

    void findPaths(vector<vector<int>>& adjMatrix, vector<vector<int>>& ans,vector<int> paths, int n, int ind) {
        if(ind == n) {
            ans.push_back(paths);
            return;
        }
        for(int j=0; j<=n; j++) {
            if(adjMatrix[ind][j] == 1) {
                paths.push_back(j);
                findPaths(adjMatrix, ans, paths, n, j);
                paths.pop_back();
            }
        }
        return;
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path = {0};
        vector<vector<int>> ans;
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        convertToAdjMatrix(graph, adjMatrix, n);
        findPaths(adjMatrix, ans, path, n-1, 0);
        return ans;
    }
};