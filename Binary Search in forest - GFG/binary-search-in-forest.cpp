// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        int maxi = INT_MIN ;
        for(int i=0 ;i<n ;i++)
        {
            if(tree[i] > maxi)
              maxi = tree[i] ;
        }

        int l = 0 ;
        int h = maxi ;
        int temp ;
        while(l<=h)
        {
            int mid = l+(h-l)/2 ;
            temp = 0 ;
            for(int i=0 ;i<n ;i++)
            {
                if(tree[i]<=mid) ;

                else
                  temp += tree[i]-mid ;

            }
            
            if(temp==k)
              return mid ;
              
            if(temp < k)
              h=mid-1;
            else
              l = mid+1 ;
              
        }
        
        return -1 ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends