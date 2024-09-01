class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.length();
        int l =0,r=0,i=0;
        while(i<n){
            while(i<n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
         if (r > 0 && s[r-1] == ' ') {
            r--;
        }
        
        return s.substr(0, r);
    }
};