    
class Solution {
private:
    
public:
// int dp[46] ;
//     int recursive(int n)
//     {          
//         if(n<0)
//             return 0 ;   
//         if(n==0)
//             return 1 ;  
        
//         if(dp[n]!=-1)
//             return dp[n] ;
        
//       dp[n] = recursive(n-1) + recursive(n-2) ;  
      
//       return dp[n] ;
//     }
//     int climbStairs(int n) 
//     {
//         memset(dp,-1 ,sizeof(dp)) ;
//         return recursive(n) ;
//     }
    
    int climbStairs(int n)
    {
         if(n==0)
               return 1 ;
         if(n==1)
              return 1 ;
        if(n==2)
              return 2 ;
        int x = 1 ;
        int y = 2 ;
        
        for(int i=3 ;i<=n ;i++)
        {
            int curr = x+y ;
            x = y ;
            y = curr ;
        }
        
        return y ;
    }
};