class Solution {
public:
    void dfs(int x ,vector<vector<int>> &adjList, vector<bool>&visited ,vector<vector<int>>&res, int i )
    {
        visited[i] = true ;
        for(auto it:adjList[i])
        {
            if(visited[it]==false)
            {
                res[it].push_back(x) ;
                dfs(x,adjList,visited,res,it) ;
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjList(n) ;
        for(int i=0 ;i<edges.size() ;i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]) ;
        }
        
        vector<vector<int>> res(n) ;
        for(int i=0 ;i<n ;i++)
        {
            int x = i ;
            vector<bool>visited(n ,false) ;
            dfs(x ,adjList,visited,res ,i) ;
        }
        
        // for(int i=0 ;i<n ;i++)
        // {
        //     sort(res[i].begin() ,res[i].end()) ;
        // }
        
        return res ;
    }
};