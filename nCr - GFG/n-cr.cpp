// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

 int mod=1e9+7;

   int nCr(int n, int r){
       // code here
       
       int dp[n+1][r+1];
       
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<r+1;j++)
           {
               if(j>i)
               {
                   dp[i][j]=0;
               }
               else if(i==j || j==0)
               {
                   dp[i][j]=1;
               }
           }
       }
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<r+1;j++)
           {
               dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
           }
       }
       
       
       
       return dp[n][r]%mod;
       
       
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends