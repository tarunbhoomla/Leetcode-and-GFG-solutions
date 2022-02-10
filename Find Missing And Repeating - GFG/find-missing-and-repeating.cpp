// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int miss= -1;
        int rep = -1 ;
        
        for(int i=0 ;i<n;i++)
        {
            arr[(arr[i]-1) %(n+1)] += (n+1) ;
        }
        
        // for(int i=0 ;i<n ;i++)
        //   arr[i] /= n+1 ;
         
        for(int i=0 ;i<n ;i++)
        {
            if(arr[i]/(n+1) <1)
              miss = i+1 ;
            else if(arr[i]/(n+1) >1 )
              rep = i+1 ;
        }

       int *res = new int[2] ; 
       res[0] = rep ;
       res[1] = miss ;
       
       return res ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends