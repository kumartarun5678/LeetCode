class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum += nums[i];

            if(i>=k){
                int l = nums[i-k];
                mp[l]--;
                sum -= l;
                if(mp[l] == 0){
                    mp.erase(l);
                }
            }

            if(i>=k-1 && mp.size() == k){
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};