// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fpath(int i,int j,vector<vector<int>> &m,string str,vector<string> &ans,vector<vector<int>> &dp,int &n){
        if(i>=n || j>=n || i<0 || j<0 || m[i][j]==0 || dp[i][j]==1) return;
        if(i==n-1 && j==n-1){
            ans.push_back(str);
            return;
        }
        dp[i][j]=1;
        fpath(i,j+1,m,str+'R',ans,dp,n);
        fpath(i+1,j,m,str+'D',ans,dp,n);
        fpath(i-1,j,m,str+'U',ans,dp,n);
        fpath(i,j-1,m,str+'L',ans,dp,n);
        dp[i][j]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int> > dp(n,vector<int>(n,0));
        vector<string> ans;
        string str="";
        fpath(0,0,m,str,ans,dp,n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends