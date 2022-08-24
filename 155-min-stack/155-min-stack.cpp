class MinStack {
public:
    stack<int> s;//normal 
    stack<int> ss;//supporting stack-min operations
    void push(int val) {
        s.push(val);
        if(ss.empty()==1||ss.top()>=val)
        ss.push(val);
    }
    void pop() {
        if(s.top()==ss.top())
        {
            s.pop();
            ss.pop();
        }
        else
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return ss.top();
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