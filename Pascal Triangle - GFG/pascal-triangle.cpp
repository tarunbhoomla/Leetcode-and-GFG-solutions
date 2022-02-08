// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
int mod = 1e9+7 ;
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<vector<ll>>  res ;
        res.push_back({1}) ;
        res.push_back({1,1}) ;
        for(int i=2;i<n ;i++)
        {
            vector<ll> temp ;
            for(int j=0 ;j<i+1 ;j++)
            {
                
                if(j==0)
                   temp.push_back(1) ;
                else if(j==i)
                   temp.push_back(1) ;
                else 
                   temp.push_back((res[i-1][j] + res[i-1][j-1])%mod );
            }
            res.push_back(temp) ;
        }
        
        return res[n-1] ;
        
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends