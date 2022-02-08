class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        long long int m = matrix.size() ;
        long long int n = matrix[0].size() ;
        vector<pair<int,int>> zeroes ;
        
        for(long long int i=0 ;i<m ;i++)
        {
            for(long long int j=0 ;j<n ;j++)
            {
                if(matrix[i][j] == 0 )
                     zeroes.push_back(make_pair(i,j)) ;
            }
        }
        
        for(long long int i=0 ; i<zeroes.size() ;i++)
        {
            long long int x = zeroes[i].first ;
            long long int y = zeroes[i].second ;
            
            for(long long int i=0 ;i<n ;i++)
                  matrix[x][i] = 0 ;
            for(long long int i=0 ;i<m ;i++)
                  matrix[i][y] = 0 ;
        }
    }
};