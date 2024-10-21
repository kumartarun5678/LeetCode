class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string str=""; 
        for(char c:s){
            if(c == '('){
                if(!st.empty())
                {
                    str += c;
                }
                st.push(c);
            }
            if(c == ')'){    
                st.pop();
                if(!st.empty())
                    str += c;
            }
            
        }
        return str;
    }
};