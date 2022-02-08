// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int dp[10001] ;
    int recursive(int i , int x, int y , int z)
    {
        if(i==0)
          return 0 ;
        
        if(dp[i] != -1)
          return dp[i] ;
        
        int  x1,y1,z1 ;
        x1=y1=z1 = INT_MIN ;
        
        if(x <= i)
          x1 = recursive(i-x , x ,y , z) ;
        if(y<=i)
          y1 = recursive(i-y ,x ,y ,z ) ;
        if(z<=i)
          z1 = recursive(i-z , x , y , z ) ;
          
        int ans = max(x1,max(y1,z1)) +1 ;
        
        return dp[i] = ans ;
        
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp ,-1 ,sizeof(dp)) ;
        int ans = recursive(n,x,y,z) ;
        if(ans<0) return 0 ;
        
        return ans ;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends