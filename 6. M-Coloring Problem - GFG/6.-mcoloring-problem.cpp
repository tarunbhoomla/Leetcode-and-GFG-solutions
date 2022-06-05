// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
int m , n ; 
vector<int> visit ;

bool check( bool graph[][101] , int v , int c)
{
    for(int u=0 ; u<n ;u++)
    {
        if(u != v && graph[u][v] && visit[u]==c)
           return false ;
        
    }
    
    return true ;
}
bool recur(bool graph[][101] ,int v)
{
    
    if(v==n)
      return true ;
    for(int c = 1 ;c <=m ;c++){
        if(!check(graph , v, c ) != 0 )
          continue ;
        
        visit[v] = c ;
        
        if(recur(graph, v+1))
           return true ;
        
        visit[v] = 0 ;
    }
    
    return false ;
}
bool graphColoring(bool graph[101][101], int m, int n) 
{
    ::m = m , ::n = n ;
    visit.assign(n,0) ;
    recur(graph , 0) ;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends