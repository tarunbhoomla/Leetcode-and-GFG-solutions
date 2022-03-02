// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
    //     multiset<long long>s ;
    //     for(long long i=0 ;i<n ;i++)
    //         s.insert(arr[i]) ;
          
    //     long long res = 0 ;
    //     long long x=0 ;
    //     long long y=0 ;
    //     while(s.size()!=1)
    //     {
    //         x = *s.begin() ;
    //         s.erase(s.begin()); 
    //         y = *s.begin() ;
    //         s.erase(s.begin()) ;
            
    //         s.insert(x+y); 
    //         res += x+y ;
    //     }
        
    //     return res ;
    // }
    
    priority_queue<long long ,vector<long long>,greater<long long>>pq ;
    for(long long i=0 ;i< n;i++)
      pq.push(arr[i]) ;
    long long cost = 0 ;
    long long x ;
    while(!pq.empty())
    {
        x = pq.top() ;
        pq.pop() ;
        if(pq.empty())
           return cost ;
        long long y = pq.top() ;
        pq.pop() ;
        x = x+y ;
        cost += x ;
        pq.push(x) ;
    }
      
      return cost ;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends