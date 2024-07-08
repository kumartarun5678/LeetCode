class Solution {
    public int countGoodNumbers(long n) {
        final int MOD = 1000000007;
        long evenCount = (n + 1) / 2; 
        long oddCount = n / 2;
        long evenResult = power(5, evenCount, MOD);
        long oddResult = power(4, oddCount, MOD);
        return (int) ((evenResult * oddResult) % MOD);
    }

    private long power(long base, long exp, int mod) {
        long result = 1;
        base = base % mod; 
        while (exp > 0) {
            if ((exp % 2) == 1) {
                result = (result * base) % mod;
            }
            exp = exp >> 1;
            base = (base * base) % mod;
        }

        return result;
    }
}
