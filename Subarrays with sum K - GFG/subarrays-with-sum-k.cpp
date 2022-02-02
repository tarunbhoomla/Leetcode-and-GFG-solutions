// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int count=0 ;
        int sum=0 ;
        unordered_map<int,int> mp ;
        for(int i=0 ;i<N ;i++)
        {
            sum = sum+Arr[i]; 
            if(sum==k)
              count++ ;
            
            if(mp.find(sum-k) != mp.end())
             {
                 count += mp[sum-k] ;
             }
            
            mp[sum]++ ;
        }
        
        return count ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends