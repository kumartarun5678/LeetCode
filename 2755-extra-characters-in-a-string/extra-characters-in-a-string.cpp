class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.length();
        unordered_set<string>st(dic.begin(),dic.end());
        vector<int>dp(n+1,0);
        for (int j = 1; j <= n; j++) {
            dp[j] =dp[j-1]+1;
            for(int i = 0;i<j;i++){
                string cur = s.substr(i, j -i);
                if (st.count(cur)) {
                    dp[j] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};