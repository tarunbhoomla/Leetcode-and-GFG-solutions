// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    static bool cmp(pair<int,int> x , pair<int,int> y)
     {
         if(x.first == y.first)
           return x.second > y.second ;
           
         else
           return x.first < y.first ;
     }
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> range ;
        for(int i=0 ;i<n ;i++)
        {
            range.push_back(make_pair(i-gallery[i]  , i+gallery[i])) ;
            
            if(range[i].first < 0)
              range[i].first = 0 ;
        }
        
        sort(range.begin() , range.end() , cmp) ;
        
       int target = 0 ;
       int ans=0 ;
       int i=0 ;
       
       while(target < n)
       {
           if(i==range.size() || range[i].first>target)
               return -1 ;                      // if target exceeds range
           
           int maxRange = range[i].second ;
           
           while(i+1 < range.size() && range[i+1].first <=target)
           {
               i++ ;
               maxRange = max(maxRange,range[i].second) ;
           }
           
           if(maxRange < target)
             return -1;
            
            ans++ ;
            target = maxRange+1 ;
            i++ ;
            
           
       }
        
        return ans ;
        
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
  // } Driver Code Ends