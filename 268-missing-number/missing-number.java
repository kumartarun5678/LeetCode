class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans=n;
        for(int i=0;i<n;i++){
            if(nums[i] != i ){
                ans = i;
                break;
            }
        }
        return ans;
    }
}