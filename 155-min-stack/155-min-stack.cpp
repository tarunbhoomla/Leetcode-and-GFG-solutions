class MinStack {
public:
    vector<pair<int,int>> res ;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(res.empty())
            res.push_back({val,val}) ;
        else
        {
            auto temp = res.back() ;
            int mini = min(val,temp.second) ;
            res.push_back({val,mini}) ;
        }
    }
    
    void pop() 
    {
        res.pop_back() ;
    }
    
    int top() 
    {
        return res.back().first ;
    }
    
    int getMin() 
    {
        return res.back().second ;
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