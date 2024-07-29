class Solution {
public:
    
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> ans;
        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                ans.push_back(arr[left]);
                left++;
            } else {
                ans.push_back(arr[right]);
                right++;
            }
        }
        
        while (left <= mid) {
            ans.push_back(arr[left]);
            left++;
        }
        
        while (right <= high) {
            ans.push_back(arr[right]);
            right++;
        }
        
        for (int i = low; i <= high; i++) {
            arr[i] = ans[i - low];
        }
    }

    int countPair(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        
        return cnt;
    }

    int mergesort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergesort(arr, low, mid);
        cnt += mergesort(arr, mid + 1, high);
        cnt += countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
        
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
