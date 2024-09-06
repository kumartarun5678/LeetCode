class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int curr, vector<int>&color,int currco){
        color[curr] = currco;
        for(auto &v:graph[curr]){
            if(color[v] == color[curr]){
                return false;
            }
            if(color[v] ==-1){
                int current = 1-currco;
                if(dfs(graph,v,color,current)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>color(n,-1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};