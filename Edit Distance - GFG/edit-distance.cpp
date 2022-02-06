// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int dp[101][101];
  int fun(string s,  string t , int m , int n)
  {
      if(m==s.size())
        return t.size() -n ;
      if(n==t.size())
         return s.size() -m ;
         
      if(dp[m][n] != -1)
        return dp[m][n] ;
         
      if(s[m]==t[n])
         return dp[m][n]=fun(s,t,m+1,n+1) ;
      
      return dp[m][n] = 1 + min( fun(s,t,m+1,n)
                     ,min(fun(s,t,m,n+1)
                     ,fun(s,t,m+1,n+1))) ;
  }
    int editDistance(string s, string t) 
    {
        memset(dp,-1,sizeof(dp)) ;
        return fun(s,t ,0,0) ;
    }

// int helper(string a,string b, int n,int m,int dp[101][101]){
//       if(n == 0) return (m);
//       if(m == 0) return (n);
       
//       if(dp[n][m] != -1) return (dp[n][m]);
       
//       if(a[n-1] == b[m-1]){
//           return dp[n][m] = helper(a,b,n-1,m-1,dp);
//       }
//       else{
//           int res1 = 1 + helper(a,b,n,m-1,dp);
//           int res2 = 1 + helper(a,b,n-1,m,dp);
//           int res3 = 1 + helper(a,b,n-1,m-1,dp);
//           return dp[n][m] = (min(res1,min(res2,res3)));
//       }
//   }

//   int editDistance(string s, string t) {
//       int dp[101][101];
//       memset(dp,-1,sizeof(dp));
//       return helper(s,t,s.length(),t.length(),dp);
//   }
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