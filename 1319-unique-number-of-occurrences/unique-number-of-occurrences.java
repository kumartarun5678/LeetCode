class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        int j = 0;
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            int ans = 1;
            while(i+1<n && arr[i]==arr[i+1]){
                ans++;
                i++;
            }
            nums[j++] = ans;
        }
        Arrays.sort(nums);
        for(int i = 1; i<nums.length;i++){
            while(nums[i]==0){
                i++;
            }
            if(nums[i] == nums[i-1]){
                return false;
            }
        }
        return true;
    }
}