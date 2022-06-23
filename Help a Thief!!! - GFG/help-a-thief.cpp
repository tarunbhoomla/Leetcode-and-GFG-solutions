// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool myFunc(pair<int,int>x ,pair<int,int>y)
    {
        if(x.second == y.second)
        {
            return x.first > y.first ;
        }
         return x.second > y.second ;
    }
    int maxCoins(int A[], int B[], int T, int N) 
    {
        int res = 0 ;
        vector<pair<int,int>> AB ;
        for(int i=0 ;i<N ;i++)
        {
            AB.push_back(make_pair(A[i] , B[i])) ;
        }
        
        sort(AB.begin() , AB.end() , myFunc) ;
        
        int i = 0 ;
        for(i=0 ;i<N ;i++)
        {
            if(T >= AB[i].first)
            {
                res += (AB[i].first*AB[i].second) ;
                T = T-AB[i].first ;
            }
            else{
                res += T*AB[i].second ;
                break ;
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
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends