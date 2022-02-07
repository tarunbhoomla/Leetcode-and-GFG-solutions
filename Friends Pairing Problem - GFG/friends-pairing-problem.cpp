// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    int countFriendsPairings(int n) 
    {    int mod = 1e9+7 ;
         long int dp[n+1] = {0} ;
         dp[0] = 0 ;
         dp[1] = 1 ;
         dp[2] = 2 ;
         for(long long int i=3 ;i<=n ;i++)
         {
            dp[i] = dp[i-1] %mod;
            dp[i] += (dp[i-2] * (i-1)) % mod;
         }
        //  int count1 = countFriendsPairings(n-1) % mod ;
        //  int count2 = (n-1)*countFriendsPairings(n-2) % mod ;
         return dp[n]%mod ;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends