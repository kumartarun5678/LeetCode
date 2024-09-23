class Solution {
public:
    int helper(int i, int &n, string &s, unordered_set<string>&st,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        int ans =1+ helper(i+1,n,s,st,dp);
        if(dp[i] !=-1){
            return dp[i];
        }
        for (int j = i; j < n; j++) {
            string cur = s.substr(i, j - i + 1);
            if (st.count(cur)) {
                ans = min(ans, helper(j + 1, n, s, st,dp));
            }
        }

        return dp[i]= ans;
    }
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.length();
        unordered_set<string>st(dic.begin(),dic.end());
        vector<int>dp(n,-1);
        return helper(0,n,s,st,dp);
    }
};