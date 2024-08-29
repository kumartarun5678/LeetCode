class MyStack {
public:
    queue<int>temp;
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = temp.front();
        temp.pop();
        return ans;
    }
    
    int top() {
        return temp.front();
    }
    
    bool empty() {
        return temp.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */