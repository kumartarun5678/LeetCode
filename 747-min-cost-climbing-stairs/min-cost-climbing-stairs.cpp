class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       int curr, prev = 0,prev1=0;
        for(int i=2;i<=n;i++){
            curr = min(cost[i-1]+prev,cost[i-2]+prev1);
            prev1 =prev;
            prev = curr;
        }
        return curr;
    }
};