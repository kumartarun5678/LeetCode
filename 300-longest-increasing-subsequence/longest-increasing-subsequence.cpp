class Solution {
public:
    int helper(vector<int>& nums, int n, int p, vector<vector<int>>& dp) {
        if (n == nums.size()) {
            return 0;
        }
        if (p != -1 && dp[n][p] != -1) {
            return dp[n][p];
        }
        
        int take = 0;
        if (p == -1 || nums[n] > nums[p]) {
            take = 1 + helper(nums, n + 1, n, dp);
        }
        
        int skip = helper(nums, n + 1, p, dp);
        
        if (p != -1) {
            dp[n][p] = max(take, skip);
        }
        
        return max(take, skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums, 0, -1, dp);
    }
};
