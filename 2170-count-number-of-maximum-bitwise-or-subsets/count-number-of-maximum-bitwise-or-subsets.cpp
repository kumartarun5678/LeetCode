class Solution {
public:
    int helper(int i, int maxor, int curror,vector<int>& nums,vector<vector<int>>& dp){
        if (i == nums.size()) {
            return (curror == maxor) ? 1 : 0;
        }
        if (dp[i][curror] != -1) {
            return dp[i][curror];
        }
        int t = helper(i + 1, maxor, curror | nums[i], nums, dp);
        int nt = helper(i + 1, maxor, curror, nums, dp);
        return dp[i][curror] = t+nt;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxor = 0;
        for(int &num:nums){
            maxor |= num;
        }
        vector<vector<int>>dp(n+1,vector<int>(maxor+1,-1));
        int curror=0;
        return helper(0,maxor,curror,nums,dp);
    }
};