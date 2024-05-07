class Solution {
    public int maxSubArray(int[] nums) {
       int n = nums.length;
       int maxele = nums[0];
       int currentSum = nums[0];
       for(int i = 1 ; i<n; i++){
            currentSum = Math.max(nums[i],nums[i]+currentSum);
            maxele  = Math.max(currentSum,maxele); 
       } 
       return (int) maxele;
    }
}