class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int zero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                nums[zero++] = nums[i];
            }
        }
        while(zero<n){
            nums[zero++] = 0;
        }
    }
}