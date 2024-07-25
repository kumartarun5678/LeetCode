class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans =0;
        int minn = prices[0];
        for(int i =0;i<n;i++){
            int cost = prices[i]-minn;
            ans = max(ans, cost);
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};