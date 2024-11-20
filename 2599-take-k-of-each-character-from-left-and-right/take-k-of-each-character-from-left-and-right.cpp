class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnt_a = 0, cnt_b = 0, cnt_c = 0;
        for (char &ch : s) {
            if (ch == 'a') cnt_a++;
            else if (ch == 'b') cnt_b++;
            else if (ch == 'c') cnt_c++;
        }
        if (cnt_a < k || cnt_b < k || cnt_c < k) {
            return -1;
        }
        int i = 0, max_length = 0;
        int remaining_a = cnt_a, remaining_b = cnt_b, remaining_c = cnt_c;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') remaining_a--;
            else if (s[j] == 'b') remaining_b--;
            else if (s[j] == 'c') remaining_c--;
            while (remaining_a < k || remaining_b < k || remaining_c < k) {
                if (s[i] == 'a') remaining_a++;
                else if (s[i] == 'b') remaining_b++;
                else if (s[i] == 'c') remaining_c++;
                i++;
            }

            max_length = max(max_length, j - i + 1);
        }
        return n - max_length;
    }
};