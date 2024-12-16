class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for(int i =0 ; i<k;i++){
            int mi = 0;
            for(int j = 1;j<n;j++){
                if(nums[j]<nums[mi]){
                    mi = j;
                }
            }
            nums[mi] *= multiplier;
        }
        return nums;
    }

};