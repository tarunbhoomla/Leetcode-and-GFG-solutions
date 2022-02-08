// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
long countWays(int n, int k)
    {
       if(n==1)return (long)k;
       if(k==1 && n>2)return 0;
       long m = 1000000007;
       
       //When n=2  
       long last_two_same = k*1;
       long last_two_diff = k*(k-1);
       long total = last_two_same + last_two_diff;
       
       for(int i=3; i<=n; i++){
          last_two_same = last_two_diff*1%m;
          last_two_diff = total*(k-1)%m;
          total = (last_two_same + last_two_diff)%m;
       }
      return total;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends