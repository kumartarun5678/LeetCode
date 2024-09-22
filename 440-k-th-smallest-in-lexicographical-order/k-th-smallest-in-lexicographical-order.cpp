class Solution {
public:
    long long helper(long long curr, long long next, long long n){
       int cnt = 0;
       while(curr<=n){
        cnt += (next-curr);
        curr *= 10;
        next *=10;
        next = min(next , n+1);
       }
       return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -=1;

        while(k>0){
            int cnt = helper(curr,curr+1,n);

            if(cnt<=k){
                curr +=1;
                k-=cnt;
            }
            else{
                curr *=10;
                k -=1;
            }
        }
        return curr;
    }
};