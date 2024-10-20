class Solution {
public:
    char helper(vector<char>&val, char op){
        if(op == '!'){
            return val[0] == 't'?'f':'t';
        }
        if(op == '&'){
            for(char &ch:val){
                if(ch == 'f'){
                    return 'f';
                }
            }
            return 't';
        }
        if(op == '|'){
            for(char &ch:val){
                if(ch == 't'){
                    return 't';
                }
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string ex) {
        int n = ex.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
            if(ex[i]==','){
                continue;
            }
            if(ex[i] == ')'){
                vector<char>val;
                while(st.top() != '('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();

                char op = st.top();
                st.pop();
                st.push(helper(val,op));
            }
            else{
                st.push(ex[i]);
            }
        }
        return st.top() == 't'? true:false;
    }
};