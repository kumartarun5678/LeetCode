class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }
        if(total & 1) {
            return false;
        }

        int target = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                bool take = false;
                if(j - nums[i-1] >= 0) {
                    take = dp[i-1][j - nums[i-1]];
                }
                bool ntake = dp[i-1][j];
                dp[i][j] = take || ntake;
            }
        }
        return dp[n][target];
    }
};
