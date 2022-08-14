class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> res ;
        vector<int> adj[numCourses] ;
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]) ;
        }
        
        vector<int>indegree(numCourses,0) ;
        for(auto it:prerequisites)
        {
            indegree[it[0]]++ ;
        }
        
        queue<int> q ;
        for(int i=0 ;i<numCourses ;i++)
        {
            if(indegree[i]==0)
                q.push(i) ;
        }
        
        while(!q.empty())
        {
            int temp = q.front() ;
            q.pop() ;
            res.push_back(temp) ;
            for(int i=0 ;i<adj[temp].size() ;i++)
            {
                indegree[adj[temp][i]]-- ;
                if(indegree[adj[temp][i]] == 0)
                    q.push(adj[temp][i]) ;
            }
        }
        
        if(res.size() != numCourses)
            return {} ;
        
        return res ;
    }
};