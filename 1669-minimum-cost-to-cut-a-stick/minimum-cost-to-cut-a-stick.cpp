class Solution {
public:
    int dp[103][103];
    int helper(vector<int>& cuts, int l, int r){
        if(r-l<2){
            return 0;
        }
        int ans = INT_MAX;
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        for(int i = l+1;i<=r-1;i++){
            int cost = cuts[r]-cuts[l] +helper(cuts,l,i)+helper(cuts,i,r);
            ans = min(ans,cost);
        }
        return dp[l][r] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        // vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        memset(dp,-1, sizeof(dp));
        return helper(cuts,0,cuts.size()-1);
    }
};