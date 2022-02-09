class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = prices[0] ;
        int sell = 0 ;
        int profit = 0 ;
        int maxProf = INT_MIN ;
        for(int i=1 ;i< prices.size() ;i++)
        {
             if(prices[i] < buy)
             {
                 buy = prices[i] ;
             }
            else
            {
                sell = prices[i] ;
                profit = sell-buy ;
                maxProf = max(maxProf,profit) ;
            }
        }
        if(maxProf==INT_MIN)
              return 0 ;
        return maxProf; 
        
        
    }
};