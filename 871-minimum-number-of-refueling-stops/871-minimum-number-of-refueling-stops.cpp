class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int res = 0;
        int curr = startFuel ;
        int index = 0 ;
        priority_queue<int> pq ;
        
        while(curr < target)
        {
            while(index<stations.size() &&  stations[index][0]<=curr)
            {
                pq.push(stations[index][1]) ;
                index++ ;
            }
            
            if(pq.empty()==true)
                return -1 ;
            
            res++ ;
            curr += pq.top() ;
            pq.pop() ;
        }
        
        return res ;
    }
};