// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
   vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        set<vector<int>> mp ;
        vector<vector<int>> res ;
        sort(arr.begin(), arr.end()) ;
        int n = arr.size() ;
        for(int i=0;i<n ;i++)
        {
            for(int j=i+1;j<n ;j++)
            {
                int x = j+1 ;
                int y = n-1 ;
                while(x<y)
                {
                    if(arr[i]+arr[j]+arr[x]+arr[y] == k)
                    {
                       mp.insert({arr[i],arr[j],arr[x],arr[y]}) ;
                       x++ ; y-- ;
                    }

                    else if(arr[i]+arr[j]+arr[x]+arr[y] < k) 
                      x++ ;
                      else
                       y-- ;
                }
            }
        }
      for(auto i:mp)
        res.push_back(i) ;
      return res ;
    }
    

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends