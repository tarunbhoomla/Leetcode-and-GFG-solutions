class MyStack {
public:
    queue<int>q1,q2 ;
    int curr ;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q1.push(x) ;
        curr = x ;
    }
    
    int pop() 
    {

        while(q1.size() > 1)
        {
            curr = q1.front() ;
            q1.pop() ;
            q2.push(curr) ;
        }
        int top1 = q1.front() ;
        q1.pop() ;
        
        while(!q2.empty())
        {
            int temp = q2.front() ;
            q2.pop() ;
            q1.push(temp) ;
        }
        
        return top1 ;
    }
    
    int top() 
    {
        return  curr ;
    }
    
    bool empty() 
    {
        return q1.empty() &&  q2.empty() ;
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