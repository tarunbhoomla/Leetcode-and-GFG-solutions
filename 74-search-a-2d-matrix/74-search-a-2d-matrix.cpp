class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0;
        while(i < m && matrix[i][n - 1] < target)
            i++;
    
        if(i >= m)
          return false;
            
         int a = 0, b = n - 1;
         while(a <= b)
        {
          int mid = a + (b - a) / 2;
          if(matrix[i][mid] == target)
                return true;
        
          if(matrix[i][mid] < target)
               a = mid + 1;
          else
               b = mid - 1;
    }
    
        return false;
        
    }
};