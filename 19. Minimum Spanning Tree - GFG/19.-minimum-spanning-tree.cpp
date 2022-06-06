// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX) ;
        vector<bool>mst(V,false) ;
        vector<int> parent(V,-1) ;
        
        key[0] = 0 ;
        
        for(int count=0 ;count<V-1 ;count++)
        {
            int mini = INT_MAX ,u  ;
            for(int i=0 ;i<V ;i++)
            {
              if(key[i]<mini &&mst[i]==false)
              {
                 mini = key[i] ;
                 u=i ;
              }
                
            }
            
            mst[u] = true ;
            for(auto it:adj[u])
            {
                int node = it[0] ;
                int wt = it[1] ;
                if(wt<key[node] && mst[node]==false)
                {
                    key[node] = wt ;
                    parent[node] = u ;
                }
            }
            
        }
        
        int sum =0 ;
        
        for(auto it:key)
        {
            sum += it ;
        }
        
        return sum  ;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends