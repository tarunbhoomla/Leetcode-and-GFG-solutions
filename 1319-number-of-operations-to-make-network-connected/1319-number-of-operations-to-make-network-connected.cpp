class Solution {
public:
    void dfs(vector<int> adj[] , vector<bool> &vis , int i)
    {
        vis[i] = true ;
        
        for(auto it:adj[i])
        {
            if(vis[it]==false)
              dfs(adj ,vis ,it) ;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size() < n-1)
              return -1 ;
        
        vector<int>ad[n] ;
        for(int i=0 ; i<connections.size() ;i++)
        {
            ad[connections[i][0]].push_back(connections[i][1]) ;
            ad[connections[i][1]].push_back(connections[i][0]) ;
        }
        
        int islands = 0 ;
        vector<bool>vis(n,false) ;
        
        for(int i=0 ; i<n ;i++)
        {
            if(vis[i]==false)
            {
                dfs(ad , vis , i) ;
                islands++ ;
            }
        }
        
        return islands-1 ;
    }
};