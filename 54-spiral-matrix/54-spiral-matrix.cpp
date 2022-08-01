class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        
        int top = 0 ;
        int bottom = m-1 ;
        int left = 0 ;
        int right = n-1 ;
        
        vector<int> res ;
        
         while(left<=right || top<=bottom)
         {
             if(left<=right){
            for(int i=left ;i<=right ;i++)
            {
                res.push_back(matrix[top][i]) ;

            }
            top++ ;
             }
             else
                 break ;
            if(top<=bottom){
            for(int i=top ;i<=bottom ;i++)
            {
                res.push_back(matrix[i][right]) ;

            }
            right-- ;
            }
             else break ;
           if(left<=right){
            for(int i=right ;i>=left ;i--)
            {
                res.push_back(matrix[bottom][i]) ;

            }
            bottom-- ;
           }
             else break ;
 
            if(top<=bottom){
            for(int i=bottom ;i>=top ;i--)
            {
                res.push_back(matrix[i][left]) ;

            }
            left++ ;
            }
             else break ;

        }
        
        return res ;
        
    }
};