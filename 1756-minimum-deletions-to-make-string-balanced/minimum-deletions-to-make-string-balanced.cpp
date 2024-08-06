class Solution {
public:
    int minimumDeletions(string s) {
        int n= s.size();
        stack<char> str;
        str.push(s[0]);
        int cnt=0;
        for(int i = 1;i<n;i++){
            if(!str.empty() &&(str.top()=='b' && s[i] == 'a')){
               str.pop();
                cnt++;
            }
            else{
                str.push(s[i]);
            }
        }
        return cnt;
    }
};