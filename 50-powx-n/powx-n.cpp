class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        double ans = 1.0;
        if (nn < 0) {
            nn = -nn;
            x = 1 / x;
        }
        while(nn>0){
            if(nn%2 == 1){
                ans *= x;
                nn--;
            }
            else{
                x *= x;
                nn /=2;
            }
        }
        return ans;
    }
};