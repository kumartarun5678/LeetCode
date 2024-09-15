class Solution {
public:
    bool helper(int i, int n, vector<int>& nums, int t, vector<vector<int>>&dp){
        if(i >= n){
            return false;
        }
        if(t<0){
            return false;
        }
        if(t == 0){
            return true;
        }
        if(dp[i][t]!= -1){
            return dp[i][t];
        }
        bool take = helper(i+1,n,nums,t-nums[i],dp);
        bool ntake = helper(i+1,n,nums,t-0,dp);

        return dp[i][t] = take or ntake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total & 1){
            return false;
        }
        int target = total /2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(0,n,nums,target,dp);
    }
};