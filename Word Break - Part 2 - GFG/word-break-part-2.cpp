// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

void recursive(unordered_set<string> mp,string s,string str ,vector<string> &res)
{
   if(s.length()==0) 
   {
       str.pop_back() ;
       res.push_back(str);
       return;
   }
   
   for(int i=0;i<s.length();i++)
   {
       string left=s.substr(0,i+1);
       if(mp.find(left)!=mp.end())
       {
           string right=s.substr(i+1);

           recursive(mp,right,str+left+" ",res);
       }
   }
}
vector<string> wordBreak(int n, vector<string>& dict, string s)
 {
    string str="";
    vector<string> res;
    unordered_set<string> mp;
    for(int i=0;i<n;i++)
    {
      mp.insert(dict[i]) ;
    }
    recursive(mp,s,str,res);
    return res;
  }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends