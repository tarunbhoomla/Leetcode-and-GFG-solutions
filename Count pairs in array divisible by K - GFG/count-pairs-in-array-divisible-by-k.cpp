// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        int freq[K] = {0} ;
        
        for(int i=0 ;i<n ;i++)
        {
            ++freq[A[i]%K] ;
        }
        
        long long res = 0 ;
        res +=  freq[0] * (freq[0]-1)/2  ;
        
        for(int i=1 ;i<=K/2 && i!=(K-i) ; i++)
            res += freq[i]*freq[K-i] ;
        
        if(K%2==0)
          res+= freq[K/2] * (freq[K/2]-1) / 2 ;
          
        return res ;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends