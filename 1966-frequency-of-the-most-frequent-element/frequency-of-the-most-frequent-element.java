import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        long left = 0, right = 0;
        long total = 0, ans = 0;

        while (right < n) {
            total += nums[(int)right];
            while ((nums[(int)right] * (right - left + 1)) > (total + k)) {
                total -= nums[(int)left];
                left++;
            }
            ans = Math.max(ans, (right - left + 1));
            right++;
        }
        return (int)ans;
    }
}
