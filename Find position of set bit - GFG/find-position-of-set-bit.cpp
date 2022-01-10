// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) 
    {
        if(n==0)
         return -1 ;
        if(n&(n-1))
            return -1 ;
        int pos = 0 ;
        while(n)
        {
            n = n/2 ; pos++ ;
        }
        
        return pos ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends