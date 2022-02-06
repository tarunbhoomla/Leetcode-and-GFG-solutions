// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//   int dp[101][101];
//   int fun(string s,  string t , int m , int n)
//   {
//       if(m==s.size())
//         return t.size() -n ;
//       if(n==t.size())
//          return s.size() -m ;
         
//       if(dp[m][n] != -1)
//         return dp[m][n] ;
         
//       if(s[m]==t[n])
//          return dp[m][n]=fun(s,t,m+1,n+1) ;
      
//       return dp[m][n] = 1 + min( fun(s,t,m+1,n)
//                      ,min(fun(s,t,m,n+1)
//                      ,fun(s,t,m+1,n+1))) ;
//   }
//     int editDistance(string s, string t) 
//     {
//         memset(dp,-1,sizeof(dp)) ;
//         return fun(s,t ,0,0) ;
//     }

int editDistance(string s, string t) 
{
    int dp[s.size()+1][t.size()+1] = {0};
    
    for(int i=0 ;i<=s.size() ;i++)
    {
        dp[i][0] = i ;
    }
    for(int i=0 ;i<=t.size() ;i++)
    {
        dp[0][i] = i ;
    }
    
    for(int i=1 ;i<=s.size() ;i++)
    {
        for(int j=1 ;j<=t.size() ;j++)
        {
            if(s[i-1] == t[j-1])
               dp[i][j] = dp[i-1][j-1] ;
            else
               dp[i][j] = 1 + min(dp[i-1][j]   , min(dp[i][j-1] , dp[i-1][j-1])) ;
        }
    }
    
    return dp[s.size()][t.size()] ;
}

};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends