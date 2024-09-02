class Solution {
public:
    int get(char s) {
        switch(s) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int sum = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int current = get(s[i]);
            int next = (i + 1 < n) ? get(s[i + 1]) : 0;

            if (current < next) {
                sum -= current;
            } else {
                sum += current;
            }
        }
        return sum;
    }
};
