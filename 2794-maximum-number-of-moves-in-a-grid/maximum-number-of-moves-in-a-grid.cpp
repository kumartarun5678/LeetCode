class Solution {
public:
    int n, m;
    
    // Memoization table
    vector<vector<int>> dp;

    // Recursive helper function to find the maximum moves from (i, j)
    int helper(int i, int j, vector<vector<int>>& grid) {
        // Base case: If out of bounds
        if (i < 0 || i >= n || j >= m) {
            return 0;
        }
        
        // Return the cached result if already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Variable to store maximum moves from (i, j)
        int maxMoves = 0;

        // Possible movements: down-right, right, up-right
        for (int newRow : {i - 1, i, i + 1}) {
            if (newRow >= 0 && newRow < n && j + 1 < m && grid[newRow][j + 1] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + helper(newRow, j + 1, grid));
            }
        }

        // Store the result in the memoization table
        dp[i][j] = maxMoves;
        return dp[i][j];
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Initialize the memoization table with -1
        dp.assign(n, vector<int>(m, -1));
        int maxResult = 0;

        // Start from each cell in the first column
        for (int i = 0; i < n; ++i) {
            maxResult = max(maxResult, helper(i, 0, grid));
        }

        return maxResult;
    }
};
