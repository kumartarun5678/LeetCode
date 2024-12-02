class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;  
        int n = sentence.size();
        int start = 0; 
        
        for (int i = 0; i <= n; ++i) {
            if (i == n || sentence[i] == ' ') {
                string word = sentence.substr(start, i - start);
                if (word.find(searchWord) == 0) {
                    return wordIndex;
                }
                wordIndex++;
                start = i + 1;
            }
        }
        return -1;
    }
};
