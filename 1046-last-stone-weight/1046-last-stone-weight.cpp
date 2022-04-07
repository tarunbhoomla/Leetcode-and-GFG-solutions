class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> stns ;
        for(auto x:stones)
        {
            stns.push(x) ;
        }
        
        while(stns.size()>1)
        {
            int y = stns.top() ;
            stns.pop() ;
            int z = stns.top() ;
            stns.pop() ;
            
            if(y==z)
                continue ;
            else
            {
                stns.push(abs(y-z)) ;
            }
        }
        if(stns.empty())
            return 0 ;
        return stns.top() ;
    }
};