// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
static bool cmp(int x, int y)
  {
      return x>y ;
  }
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N) ;
        int l=0 ,h=N-1 ;
        int mini = 0 ;
        while(l <= h)
        {
            mini += candies[l] ;
            l++ ;
            h = h-K ;
        }
        
        sort(candies,candies+N,cmp) ;
         l=0;
         h=N-1 ;
        int maxi = 0 ;
        while(l <= h)
        {
            maxi += candies[l] ;
            l++ ;
            h = h-K ;
        }
        
        return {mini,maxi} ;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends