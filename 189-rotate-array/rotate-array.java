class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        rot(nums, 0,n-1);
        rot(nums,0,k-1);
        rot(nums,k,n-1);
    }
    private void rot(int[] nums, int start, int end){
        while(start<end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end]= temp;
            start++;
            end--;
        }
    }
}