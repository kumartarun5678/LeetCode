class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int>pq(nums.begin(),nums.end());

        while(k--){
            int maxe = pq.top();
            pq.pop();

            sum += maxe;

            maxe = ceil(maxe/3.0);
            pq.push(maxe);
        }
        return sum;
    }
};