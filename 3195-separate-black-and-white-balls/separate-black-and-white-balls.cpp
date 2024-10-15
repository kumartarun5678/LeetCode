class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        int cnnn = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '0'){
                cnt+=(long long)cnnn;
            } 
            else{
                cnnn++;
            }
            
        }
        return cnt;
    }
};
