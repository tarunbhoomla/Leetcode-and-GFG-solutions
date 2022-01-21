// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int x , vector<int> adj[] , int v , vector<int>&res , vector<bool>&vis)
    {
        vis[x] = true ;
        res.push_back(x) ;
        
        for(auto neigh : adj[x] )
        {
            if(vis[neigh]==false)
               dfs(neigh , adj ,v , res , vis) ;
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> res ;
        vector<bool>vis(V,false) ;
        
        dfs(0 , adj , V , res , vis) ;
        
        return res ;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends