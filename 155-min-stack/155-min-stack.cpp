class MinStack {
    vector<long long int> stack;
    long long int minimum;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty()){
            minimum = val;
            stack.push_back(val);
            return;
        }
        if(val>minimum){
            stack.push_back(val);
        }else{
            stack.push_back(2LL*val-minimum);
            minimum = val;
        }
        return;
    }
    
    void pop() {
        long long int Top = stack.back();
        if(Top<minimum) minimum = 2LL*minimum-Top;
        stack.pop_back();
        return;
    }
    
    int top() {
        long long int Top = stack.back();
        if(Top<minimum) return minimum;
        else return Top;
    }
    
    int getMin() {
        return minimum;
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