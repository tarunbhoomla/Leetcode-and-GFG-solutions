// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void dfs(unordered_map<int,pair<int,int>>mp ,int src,vector<int>&v ,int &min)
    {
        if(mp.find(src)!=mp.end())
        {
            pair<int,int> p =mp[src];
            if(min > p.second)
              min = p.second;
         dfs(mp,p.first,v,min) ;}
            else
            {
                v.push_back(src) ;
                v.push_back(min) ;
            }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        unordered_map<int,pair<int,int>>outgoing;
        unordered_map<int,int>incoming;
        vector<vector<int>>res ;
        
        for(int i=0 ;i<p ;i++)
        {
            outgoing[a[i]] = {b[i],d[i]} ;
            incoming[b[i]] = a[i] ;
        }
        for(int i=1 ;i<=n ;i++)
        {
            if(outgoing.find(i)!= outgoing.end()
              && incoming.find(i)==incoming.end())
              {
                  vector<int>temp ;
                  int min = INT_MAX ;
                  temp.push_back(i) ;
                  dfs(outgoing,i,temp ,min) ;
                  res.push_back(temp); 
              }
        }
        
        return res ;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends