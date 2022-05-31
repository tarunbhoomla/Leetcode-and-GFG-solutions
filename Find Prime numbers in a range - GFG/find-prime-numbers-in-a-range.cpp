// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPrime(int x)
    {
        if(x<2)
          return false ;
        
        for(int i=2 ;i<=sqrt(x) ;i++)
        {
            if(x%i == 0 )
              return false ;
        }
        
        return true ;
    }
    vector<int> primeRange(int M, int N) 
    {
        vector<int> res ;
        
        for(int i=M ;i<=N ;i++)
        {
            if(i==2 || (i%2 !=0))
            {
                if(isPrime(i))
                   res.push_back(i) ;
            }
        }
        
        return res ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends