class Solution {
public:
    int minLength(string s) {
        int n  = s.size();
        for(int i=0;i<n-1;){
            string ch = s.substr(i,2);
            if(ch == "AB" || ch == "CD"){
                s.erase(i, 2);
                n = n-2;
                if(i>0){
                    i--;
                }
            }
            else{
                i++;
            }
        }
        return s.size();
    }
};