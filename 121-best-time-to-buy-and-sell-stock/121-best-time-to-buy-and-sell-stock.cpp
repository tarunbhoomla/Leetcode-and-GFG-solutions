class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = prices[0] ;
        int sell;
        int profit = 0 ;
        int maxProf = 0 ;
        for(int i=1 ;i< prices.size() ;i++)
        {
             if(prices[i] < buy)
             {
                 buy = prices[i] ;
             }
            else
            {

                profit = prices[i]-buy ;
                maxProf = max(maxProf,profit) ;
            }
        }

        return maxProf; 
        
        
    }
};