class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjl[n];
        for(int i = 0;i<n;i++){
            for(int  j =0;j<n;j++){
                if(isConnected[i][j] ==1 && i!=j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        int cnt =0;
        vector<int>vis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjl,vis);
            }
        }
        return cnt;
    }
};