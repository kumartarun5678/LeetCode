class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        long long sum = 0;
        for(auto &gift:gifts){
            sum += gift;
        }
        long long mysum = 0;
        while(k--){
           int  maxEle = pq.top();
            pq.pop();
            int rem = sqrt(maxEle);
            mysum += maxEle-rem;
            pq.push(rem);
        }
        return sum -mysum;
    }
};