class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        long ans = 0;
        boolean neg = false;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (i == 0) {
                if (ch == '-') {
                    neg = true;
                    continue;
                } else if (ch == '+') {
                    neg = false;
                    continue;
                }
            }
            if (Character.isDigit(ch)) {
                int dig = ch - '0';
                ans = ans * 10 + dig;
                if (neg) {
                    long check = -ans;
                    if (check < Integer.MIN_VALUE) {
                        return Integer.MIN_VALUE;
                    }
                } else {
                    if (ans > Integer.MAX_VALUE) {
                        return Integer.MAX_VALUE;
                    }
                }
            } else {
                break;
            }
        }
        if (neg) {
            ans = -ans;
        }
        return (int)ans;
    }
}
