class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        vector<int> temp ;
        
        for(int r=0 ;r<n ;r++)
        {
            temp.clear() ;
            
            for(int i=r ,j=0 ; i<n && j<m ;i++ ,j++)
                temp.push_back(mat[i][j]) ;
            
            sort(temp.begin() ,temp.end()) ;
            
            for(int i=r ,j=0 ; i<n && j<m ;i++ ,j++)
                mat[i][j] = temp[j] ;
        }
        
        for(int r=1 ;r<m ;r++)
        {
            temp.clear() ;
            for(int i=0 ,j=r ; i<n && j<m ;i++ ,j++)
                 temp.push_back(mat[i][j]) ;
            
            sort(temp.begin() ,temp.end()) ;
            
            for(int i=0 ,j=r ; i<n && j<m ;i++ ,j++)
                mat[i][j] = temp[i] ;
            
        }
        
        return mat ;
        
    }
};