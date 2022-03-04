// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // int median(vector<vector<int>> &matrix, int r, int c)
    // {
    //     int tot = (r-1)*(c-1) ;
    //     int maxi = -1 ;
    //     for(int i=0 ;i<r ;i++)
    //       if(matrix[i][c-1] > maxi)
    //          maxi = matrix[i][c-1] ;
        
    //     int l = 0 ;
    //     int h = maxi ;
        
    //     while(l<=h)
    //     {
    //         int mid = l+(h-l)/2 ;
            
    //         int count = 0 ;
    //         int maxoo = 0 ;
    //         for(int i=0 ;i<r ;i++)
    //         {
    //             int l1 = 0 ;
    //             int h2 = c-1 ;
                
    //             while(l1 <= h2)
    //              {
    //                  int midi =  l1+(h2-l1)/2; 
    //                  if(matrix[i][midi] <= mid)
    //                     l1 = mid+1 ;
    //                  else
    //                     h1 = mid-1 ;
    //              }
    //             count += l1 ;
    //             maxo = l1 ;
    //         }
            
            
    //         if(count == tot/2)
    //           return maxo ;
            
            
           
            
    //     }
             
    // }
    
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here
        int low=INT_MAX, high=INT_MIN;
        for(int i=0;i<r;i++)
        {
            low=min(low,matrix[i][0]) ;
            high= max(high ,matrix[i][c-1]) ;
        }
        int mid=0 ;

        while(low<=high)
        {
             mid =(low+high)/2;
            int count =0;

            for(int i=0;i<r;i++)
            {
            int l=0,h=c-1;

            while(l<=h)
            {
                int m= (l+h)/2;
                if(matrix[i][m]>mid)
                {
                    h=m-1;

                }else {
                    l=m+1;
                }
            }
            count +=l;
            }

             if(count >(r*c)/2)
            {
                high=mid-1;

            }else {
                low=mid+1;
            }
        }
        return low ;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends