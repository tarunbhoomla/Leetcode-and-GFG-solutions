// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    long long int l = 0 ;
	    long long int h = m ;
	    int mid = -1 ;
	    while(l<=h)
	    {
	        mid = (l+h)/2 ;
	        if(pow(mid,n)==m)
	          return mid ;
	        else if(pow(mid,n) < m)
	           l=mid+1 ;
	         else
	           h = mid-1 ;
	        
	    }
	    return -1 ;
	    
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends