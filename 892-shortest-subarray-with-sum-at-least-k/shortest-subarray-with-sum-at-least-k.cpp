class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<long long> sum(n, 0); 
        int ans = INT_MAX;
        int i=0;
        while(i<n){
            if(i==0){
                sum[i] = nums[i];
            }
            else{
                sum[i] =sum[i-1] +nums[i];
            }
            if(sum[i] >= k){
                ans = min(ans,i+1);
            }

            while(!deq.empty() && sum[i]-sum[deq.front()]>=k){
                ans = min(ans,i-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && sum[i]<=sum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
            i++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};