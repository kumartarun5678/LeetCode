class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char sh : s){
            num += to_string(sh - 'a'+1);
        }
        while(k>0){
            int sum = 0;
            for(char ans : num){
                sum += ans - '0';
            }
            num = to_string(sum);
            k--;
        }
        return stoi(num);
    }
};