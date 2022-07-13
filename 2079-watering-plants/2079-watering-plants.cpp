class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps = 0 ;
        for(int i=0 ;i<plants.size() ;i++)
        {
            int cap = capacity ;
            while(i<plants.size() && plants[i]<=cap)
            {
                steps++ ;
                cap -= plants[i] ;
                i++ ;
            }
            if(i>=plants.size())
                break ;
            i-- ;             

            steps += 2*(i+1) ;
        }
        
        return steps ;
    }
};