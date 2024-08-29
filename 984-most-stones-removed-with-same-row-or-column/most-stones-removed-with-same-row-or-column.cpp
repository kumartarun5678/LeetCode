class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i = 0;i<n;i++){
            if(vis[i] == true){
                continue;
            }
            dfs(stones,i,vis);
            cnt++;
        }
        return n-cnt;
    }
    void dfs(vector<vector<int>>&stone, int in, vector<bool>&vis){
        vis[in] = true;
        for(int i =0;i<stone.size();i++){
            int r = stone[in][0];
            int c = stone[in][1];
            if(!vis[i] &&(stone[i][0]==r ||stone[i][1] == c)){
                dfs(stone,i,vis);
            }
        }
    }
};