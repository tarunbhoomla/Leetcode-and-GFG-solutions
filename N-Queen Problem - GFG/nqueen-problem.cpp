// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSafe(int i,int j,vector<string> &temp)
{
   for(int p=0;p<i;p++)
   {
       for(int q=0;q<temp.size();q++)
       {
           if(temp[p][q]=='Q')
           {
               if(q==j || abs(i-p)==abs(j-q))
               return false;
           }
       }
   }
   return true;
}
void solve(int i,int n,vector<int> &v,
vector<vector<int>> &ans,vector<string> &temp)
{
   if(i==n)
   {
       ans.push_back(v);
       return;
   }
   for(int j=0;j<n;j++)
   {
       if(isSafe(i,j,temp))
       {
           temp[i][j]='Q';
           v.push_back(j+1);
           solve(i+1,n,v,ans,temp);
           temp[i][j]='.';
           v.pop_back();
       }
   }
   return;
}
   vector<vector<int>> nQueen(int n) 
   {

       vector<vector<int>> ans;
       vector<int> v;
       vector<string> temp(n, string(n, '.'));
       solve(0,n,v,ans,temp);
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends