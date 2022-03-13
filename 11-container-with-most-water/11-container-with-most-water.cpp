class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int res = INT_MIN ;
        int walls = height.size() ;
        
        int i=0 ;
        int j=walls-1;
        while(i<j)
        {
                int h1 = height[i] ;
                int h2 = height[j] ;
                
                int temp = (j-i)*(min(h1,h2)) ;
                if(temp>res)
                     res = temp ;
                if(h1>=h2)
                {
                    j-- ;
                }
               else
               {
                   i++ ;
               }
        }
//         for(int i=0 ;i<walls-1 ;i++)
//         {
//             for(int j=i ;j<walls ;j++)
//             {
//                 int h1 = height[i] ;
//                 int h2 = height[j] ;
                
//                 int temp = (j-i)*(min(h1,h2)) ;
//                 if(temp>res)
//                      res = temp ;
//             }
//         }
        
        return res ;
    }
};