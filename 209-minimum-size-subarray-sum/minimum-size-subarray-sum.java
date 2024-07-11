class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int  n = nums.length;
        int start = 0;
        int end = n-1;
        int sum =0;
        int min = Integer.MAX_VALUE;
        int left = 0;
        while(start<=end){
            sum += nums[start];
            while(sum>=target){
                min = Math.min(min,start-left+1);
                sum -= nums[left];
                left++;
            }
            start++;
        }
        return (min == Integer.MAX_VALUE) ? 0 : min;
    }
}