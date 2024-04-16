class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i = 0;
        int j=0;
        int cnt =0;
        long pdt = 1;
        int n = nums.length;
        while(i<n){
            pdt *= nums[i];
            while(pdt>=k && i>= j){
                pdt /= nums[j];
                j++;
            }
            cnt += (i-j+1);
            i++;
        }
        return cnt;
    }
}