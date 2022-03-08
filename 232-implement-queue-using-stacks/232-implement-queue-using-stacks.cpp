class MyQueue {
public:
    stack<int> s1 ,s2 ;
    int frnt ;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        if(s1.empty())
        {
            s1.push(x) ;
            frnt = x ;
        }
        else
            s1.push(x) ;
        
        
    }
    
    int pop() 
    {
        while(s1.size() > 1 )
        {
            frnt = s1.top() ;
            s1.pop() ;
            s2.push(frnt) ;
        }

        int ans = s1.top() ;
        s1.pop() ;
        
        while(s2.size())
        {
            int temp = s2.top() ;
            s2.pop() ;
            s1.push(temp) ;
        }
        
        return ans ;
    }
    
    int peek() 
    {
        return frnt ;
    }
    
    bool empty() 
    {
        return s1.empty() && s2.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */