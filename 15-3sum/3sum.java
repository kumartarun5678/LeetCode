class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        Set<List<Integer>> res =new HashSet<>();
        List<List<Integer>> ans = new ArrayList<>();

        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    res.add(Arrays.asList(nums[i],nums[j],nums[k]));
                    
                    j++;
                    k--;
                }
                else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }

        }
        ans.addAll(res);
        return ans;
    }
}