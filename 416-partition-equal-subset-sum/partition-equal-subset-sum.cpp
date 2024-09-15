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
        vector<int>curr(total+1,0);
        vector<int>next(total+1,0);
        curr[0] = 1;
        next[0] = 1;
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j <= target; j++) {
                bool take = false;
                if(j - nums[i-1] >= 0) {
                    take = next[j - nums[i-1]];
                }
                bool ntake = next[j];
                curr[j] = take || ntake;
            }
            next = curr;
        }
        return next[target];
    }
};
