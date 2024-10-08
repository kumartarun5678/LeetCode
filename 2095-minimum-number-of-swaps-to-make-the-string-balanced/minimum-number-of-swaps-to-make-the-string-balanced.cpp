class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char>st;
        int cnt = 0;
        for(char & ch:s){
            if(ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        return (st.size()+1)/2;
        
    }
};