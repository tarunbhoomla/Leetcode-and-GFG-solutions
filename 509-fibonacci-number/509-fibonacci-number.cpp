class Solution {
public:
    int fib(int n) 
    {
        if(n==0)
              return 0 ;
        if(n==1)
              return 1 ;
        
        int prev = 0 ;
        int curr = 1 ;
        int temp ;
        for(int i=2 ; i<=n ;i++)
        {
            temp = prev+curr ;
            prev = curr ;
            curr = temp ;
        }
        
        return curr ;
    }
};