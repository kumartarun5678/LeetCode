class Solution {
public:
    int findrowsum(vector<vector<int>>& grid, int r, int c){
        int sum = 0;
        bool vis[10];
        for(int i = 0;i<3;i++){
            int rowsum = 0;
            for(int j = 0;j<3;j++){
                int val = grid[r+i][c+j];
                if(val == 0||val>=10|| vis[val]){
                    return -1;
                }
                vis[val] =true;
                rowsum +=val;
            }
            if(i==0){
                sum = rowsum;
            }
            else{
                if(sum != rowsum){
                    return -1;
                }
            }
        }
    return sum;
    }
    int findcolsum(vector<vector<int>>& grid, int r, int c){
        int sum = 0;
        for(int i = 0;i<3;i++){
            int colsum = 0;
            for(int j = 0;j<3;j++){
                int val = grid[r+j][c+i];
                colsum +=val;
            }
            if(i==0){
                sum = colsum;
            }
            else{
                if(sum != colsum){
                    return -1;
                }
            }
        }
        return sum;
    }
    int finddiasum(vector<vector<int>>& grid, int r, int c){
        int sum1 = grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        int sum2 = grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
        if(sum1 == sum2){
            return sum1;
        }
        return -1;
    }
    bool helper(vector<vector<int>>& grid, int r, int c){
        int rsum = findrowsum(grid,r,c);
        if(rsum ==-1){
            return false;
        }
        int csum = findcolsum(grid,r,c);
        if(csum ==-1){
            return false;
        }
        int dsum = finddiasum(grid,r,c);
        if(dsum ==-1){
            return false;
        }
        if(rsum == csum && rsum==dsum){
            return true;
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        for(int i =0;i<n-2;i++){
            for(int j = 0;j<m-2;j++){
                if(helper(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};