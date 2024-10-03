class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = (sum+nums[i])%p;
        }
        int cnt = n;
        int tar = sum%p;
        if(tar == 0){
            return 0;
        }
        unordered_map<int, int>mpp;
        int curr =0;
        mpp[0] = -1;
        for(int i=0;i<n;i++){
            curr = (curr+nums[i])%p;
            int rem = (curr-tar+p)%p;
            if(mpp.find(rem) != mpp.end()){
                cnt = min(cnt,i-mpp[rem]);
            }
            mpp[curr] = i;
        }
        return cnt == n?-1:cnt;
    }
};