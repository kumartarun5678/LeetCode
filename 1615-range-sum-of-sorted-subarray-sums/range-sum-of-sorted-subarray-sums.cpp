#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int m = n*(n+1)/2;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum =(sum+ nums[j])%MOD;
                arr.push_back(sum);
        }
    }
        sort(arr.begin(),arr.end());
        long long sum = 0;
        for(int i = left-1;i<right;i++){
            sum =(sum+ arr[i])%MOD;
        }
        return sum;
    }
};