class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=n || j<0 ||j>=m || grid[i][j] != '1'){
            return;
        }
        if(grid[i][j] ==-1){
            return;
        }

        grid[i][j] = 'k';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};