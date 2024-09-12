class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int res = nums[0];
        int prevMin = 1;
        int prevMax = 1;

        for(auto num: nums){
            int temp = max(num,max(prevMax*num,prevMin*num));
            prevMin = min(num,min(prevMin*num, prevMax*num));
            prevMax = temp;
            res = max(res,prevMax);
        }
        return res;
    }
};