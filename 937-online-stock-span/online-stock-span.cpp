class StockSpanner {
public:
    stack<pair<int, int>>st;
    int in = -1; 
    StockSpanner() {
        in = -1;
        st.empty();
    }
    
    int next(int price) {
        in = in +1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans =in - (st.empty()?-1:st.top().second);
        st.push({price,in});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */