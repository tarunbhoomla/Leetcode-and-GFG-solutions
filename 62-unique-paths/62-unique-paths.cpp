class Solution {
public:
    int dp[101][101] ;
    int recursive( int m , int n , int x , int y)
    {
        if(x==m-1 && y==n-1)
              return 1 ;
        if(dp[x][y]!=-1)
              return dp[x][y] ;
        int count1 = 0 ;
        int count2 = 0 ;
        if(x<m-1)
            count1 = recursive(m,n,x+1,y) ;
        if(y<n-1)
            count2 = recursive(m,n,x,y+1);
        
        return dp[x][y] =count1+count2 ;
    }
    int uniquePaths(int m, int n) 
    {  
        memset(dp,-1,sizeof(dp));
        return recursive(m,n , 0 ,0) ;
    }
};