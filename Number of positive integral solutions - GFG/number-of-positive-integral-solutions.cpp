// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends


#include<bits/stdc++.h>
class Solution{
public:

  long long xxx(int temp,int no,vector<vector<int>>&dp)
  {
      if(no==1)return 1;
      
      if(dp[temp][no]!=-1)return dp[temp][no];
      
      long long ans=0;
      int n=(temp-no+1);
      for(int aa=1;aa<=n;aa++)
      {
          long long ttt=xxx(temp-aa,no-1,dp);
          ans+=ttt;
      }
      return dp[temp][no]=ans;
  }

   long posIntSol(string s)
   {
       int no=0,tmp,i=0;
       for(;i<s.size();i++)
       {
           if(s[i]=='=')break;
           
           if(s[i]=='+')continue;
           else no++;
       }
     
       string ss=s.substr(i+1);
       tmp=stoi(ss);
       
       vector<vector<int>>dp(tmp+1,vector<int>(no+1,-1));
       
       return xxx(tmp,no,dp);
       
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends