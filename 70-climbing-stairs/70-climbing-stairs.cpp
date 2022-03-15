    
class Solution {
private:
    int dp[46] ;
public:
    
    int recursive(int n)
    {          
        if(n<0)
            return 0 ;   
        if(n==0)
            return 1 ;  
        
        if(dp[n]!=-1)
            return dp[n] ;
        
      dp[n] = recursive(n-1) + recursive(n-2) ;  
      
      return dp[n] ;
    }
    int climbStairs(int n) 
    {
        memset(dp,-1 ,sizeof(dp)) ;
        return recursive(n) ;
    }
};