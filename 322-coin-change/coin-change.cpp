class Solution {
public:
    int bfs(int i, vector<int>& coins, int amt, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amt % coins[0] == 0)
                return amt/coins[0];
            return 1e9;
        }
        
        if (dp[i][amt] != -1) return dp[i][amt];
        
        int notTake = 0 + bfs(i - 1, coins, amt, dp);
        int take = INT_MAX;
        if (coins[i] <= amt) {
            take =1 + bfs(i, coins, amt - coins[i], dp);
        }
        return dp[i][amt] =min (notTake , take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans =  bfs(n - 1, coins, amount, dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }

};