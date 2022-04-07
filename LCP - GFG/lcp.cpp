// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
         sort(ar , ar+n);
         
         string str1 = ar[0] ;
         string str2 = ar[n-1] ;
         
         string res = "" ;
         int i=0 ;
         while(str1[i]==str2[i])
         {
             res+=str1[i] ;
             i++ ;
             
         }
         if(res.size()==0)
           return "-1" ;
         return res ;
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends