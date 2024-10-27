class Solution {
public:
    int n,m;
    int helper(int i,int j, vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(matrix[i][j] ==0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int left = helper(i+1,j,matrix,dp);
        int diag = helper(i+1,j+1,matrix,dp);
        int right = helper(i,j+1,matrix,dp);

        return dp[i][j] = 1+min({left,diag,right});
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] ==1)
                    ans += helper(i,j,matrix,dp);
            }
        }
        return ans;
    }
};