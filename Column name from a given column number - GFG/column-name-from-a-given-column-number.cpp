// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res="" ;
        while(n)
        {

            int  idx = n%26 ;
            char x ;
            if(idx==0 && n>0)
             {
                 x = 'Z' ;
                 n-- ;
             }
             else
             {
                x = 'A'+idx-1 ;                 
             }

            res = x + res ;
            
            n = n/26 ;
            
        }
        
        return res ;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends