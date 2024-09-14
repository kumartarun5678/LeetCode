class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int res = 0;
        int cnt = 0;
        for(int num:nums){
            if(num>maxVal){
                res= 0;
                maxVal = num;
                cnt=0;
            }
            if(maxVal == num){
                cnt++;
            }
            else{
                cnt =0;
            }
            res=max(res,cnt);
        }
        return res;
    }
};