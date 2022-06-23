// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
// 	 int rec(int N, int i,string temp)
// 	    {
	        
// 	        if(i>=N)
// 	        {
// 	            return 1 ;
// 	        }
	          
	          
// 	        if(i==0 || temp[i-1]=='S')
// 	        {
// 	            return rec(N,i+1,temp+'B') + rec(N,i+1 ,temp+'S') ; 
// 	        }
// 	        else
// 	        {
//                 return rec(N,i+1,temp+'S') ;
// 	        }
// 	    }
	    
	int TotalWays(int N)
	{
        

	   // string temp="" ;
	   // int x =  rec(N ,0 ,temp) ;
    //         x = pow(x,2) ;
	   // return (x % 1000000007);
	   
	   
	   long long mod = 1e9+7 ;
	   long long dp[N+1][2] ;
	   
	   dp[0][0] = 1 ;
	   dp[0][1] = 1 ;
	   
	   for(int i=1 ;i<N ;i++)
	   {
	       dp[i][0] = (dp[i-1][0] + dp[i-1][1]) %mod ;
	       dp[i][1] = dp[i-1][0] ;
	   }
	   
	   long long ans = (dp[N-1][0] + dp[N-1][1]) %mod ;
	   ans = (ans*ans) %mod ;
	   
	   return ans ;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends