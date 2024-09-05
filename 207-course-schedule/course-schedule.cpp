class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& dfsVis) {
        vis[node] = true;
        dfsVis[node] = true;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, dfsVis)) return true;
            } else if (dfsVis[it]) {
                return true; 
            }
        }

        dfsVis[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> dfsVis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, dfsVis)) {
                    return false; 
                }
            }
        }

        return true;
    }
};
