class Solution {
public:
    bool isSubstring(string &haystack, string &needle) {
        int len = haystack.length();
        int leng = needle.length();

        for (int i = 0; i <= len - leng; i++) {
            int j = 0;
            for (; j < leng; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == leng) {
                return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int cnt = 1;
        while (temp.size() < b.size()) {
            temp += a;
            cnt++;
        }
        if (isSubstring(temp, b)) {
            return cnt;
        }
        temp += a;
        if (isSubstring(temp, b)) {
            return cnt + 1;
        }
        return -1;
    }
};
