class Solution {
public:
    int helper(int i ,int j, string s, string str,vector<vector<int>>&dp){
        int n = s.size();
        int m = str.size();
        if(i == n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == str[j]){
            return helper(i+1,j+1,s,str,dp);
        }else{
        int insert = 1+helper(i,j+1,s,str,dp);
        int delet = 1+helper(i+1,j,s,str,dp);
        int replace = 1+helper(i+1,j+1,s,str,dp);
        // int minn = min(insert,delet);
        // int mi = min(minn,replace);
        return dp[i][j] = min({insert,delet,replace});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,dp);
    }
};