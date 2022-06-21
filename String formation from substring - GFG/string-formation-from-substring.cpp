// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n = s.length() ;
	    for(int i=1 ;i<=n/2 ;i++)
	    {
	        string x = s.substr(0,i) ;
	        if( n%i==0)
	        {
	            int m = n/i-1 ;
	            string y = x ;
	            while(m--)
	               x+= y ;
	               
	            if(x==s)
	                  return 1 ;
	            
	        }
	    }
	    
	    return 0 ;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends