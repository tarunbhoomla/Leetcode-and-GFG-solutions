// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int maxGold(int n, int m, vector<vector<int>> M)
   {
   int i, j, temp=0 ;
   //int  M1[n][m];
   for(j=1; j<m; j++)
   {
       for(int i=0; i<n; i++)
       {
           if(i-1>=0)
             temp=max(M[i][j]+M[i-1][j-1], temp);
           if (i+1<=n-1)
              temp=max(M[i][j]+M[i+1][j-1], temp);
           temp=max(M[i][j]+M[i][j-1], temp);
           
           M[i][j]=temp;
           
           temp=0;
       }
   }
   int final=0;
   for(i=0; i<n; i++)
   {
       final=max(final, M[i][m-1]);
       
       
   }
    
    return final;
   

   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends