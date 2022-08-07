
class Solution {
public:
    int mod = 1e9+7 ;
    long long fun(int n ,char prev , vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return dp[n][prev-'a'] = 1;
        }
        
        if(dp[n][prev-'a'] != -1)
            return dp[n][prev-'a'] ;
        
        if(prev=='s')
        {
           return dp[n][prev-'a'] = 1LL*(fun(n-1 ,'a' ,dp) +
            fun(n-1 ,'e',dp) % mod +
            fun(n-1 ,'i',dp) % mod +
            fun(n-1 ,'o',dp) % mod +
            fun(n-1 ,'u',dp) % mod) % mod ;
        }
        else if(prev=='a')
        {
            return dp[n][prev-'a'] = fun(n-1 ,'e' ,dp) % mod ;
        }
        else if(prev=='e')
        {
            return dp[n][prev-'a'] = (1LL* (fun(n-1 ,'a' ,dp)% mod +
            fun(n-1 ,'i' ,dp))% mod) % mod;
        }
        else if(prev=='i')
        {
            return dp[n][prev-'a'] = 1LL*
            (fun(n-1 ,'a' ,dp)% mod +
            fun(n-1 ,'e' ,dp)% mod +
            fun(n-1 ,'o' ,dp)% mod +
            fun(n-1 ,'u' ,dp)% mod) % mod ;
        }
        else if(prev=='o')
        {
            return dp[n][prev-'a'] = 1LL*(fun(n-1 ,'i',dp)% mod +
            fun(n-1 ,'u' ,dp)% mod)%mod ;
        }
        else if(prev=='u')
        {
            return dp[n][prev-'a'] = fun(n-1 ,'a' ,dp) % mod ;
        }
        else
            return 0 ;

        
    }
    int countVowelPermutation(int n) 
    {
       vector<vector<int>>dp(n+1 ,vector<int>(26,-1)) ;
       char prev = 's' ;
       long long int x = fun(n , prev ,dp) ;
        int res = x % mod ;
        return res ;
    }
};