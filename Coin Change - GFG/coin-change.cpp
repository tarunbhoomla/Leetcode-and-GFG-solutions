// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int dp[1002][1002] ;
    long long int fun(int S[], int m, int n)
    {
        
        if(n==0)
            return 1 ;
        if(m<=0 || n<0)
          return 0 ;
          
        if(dp[m][n] != -1)
           return dp[m][n] ;
        
          long long int sum1=0;
          long long int sum2=0;
          
         if(n>=S[m-1])
            sum1 = fun(S , m , n-S[m-1]) ;
            sum2 = fun(S , m-1 , n) ;
         
         return dp[m][n] = sum1+sum2 ;
        
    }
    long long int count(int S[], int m, int n) 
    {
        memset(dp,-1,sizeof(dp)) ;
        fun(S , m ,n);
        
        return dp[m][n] ;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends