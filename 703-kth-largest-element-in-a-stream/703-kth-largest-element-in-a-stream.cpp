class KthLargest {
public:
    priority_queue<int, vector<int> ,greater<int>> pq ;
    int K ;
    
    KthLargest(int k, vector<int>& nums) 
    {
        K = k ;
        for(auto it:nums)
        {
            pq.push(it) ;
            while(pq.size() >k)
                pq.pop() ;
        }
    }
    
    int add(int val) 
    {
        pq.push(val) ;
        while(pq.size() > K)
             pq.pop() ;
        
        int res = pq.top() ;
        
        return res ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */