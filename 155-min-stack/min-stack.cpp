class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {
        stack<int>st;
        stack<int>minst;
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || minst.top()>val){
            minst.push(val);
        }
        else{
            minst.push(minst.top());
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */