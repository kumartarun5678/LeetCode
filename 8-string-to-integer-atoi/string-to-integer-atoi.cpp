class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i =0;
        int sign = 1;
        int ans =0;
        while(i<n && s[i] == ' '){
            i++;
        }

        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-')?-1:1;
            i++;
        }

        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }
        return ans*sign;
    }
};