// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long l = 0 ;
        
        long h = -1 ;
        for(int i=0;i<N;i++){
           h = max(L/A[i],h);
        }
        
        long res ;
        
        long mid ;
        while(l<=h)
        {
            mid = (l+h)/2 ;
            long tot_speed = 0 ;
            for(int i=0 ; i<N ;i++)
            {
                long speed = H[i]+ mid*A[i] ;
                if(speed >= L)
                   tot_speed += speed ;
            }
            
            if(tot_speed > M)
            {
                res = mid ;
                h = mid-1 ;
            }
                

            else
               l = mid+1 ;
        }
        
        return l ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends