// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool findPath(vector<vector<int>>&m ,vector<vector<int>>&res ,int i,int j,int n)
    {
        if(i<0 || j<0 || i>=n || j>=n)
           return false ;

        if(i==n-1 &&  j==n-1)
        {
            res[i][j]=1 ;
            return true ;
        }
       if(m[i][j]==0)
         return false;
        res[i][j] = 1 ;
        int d = m[i][j] ;
        for(int k=1 ;k<=d ;k++)
        {
            if(findPath(m,res,i,j+k , n))  return true ;
            if(findPath(m,res,i+k,j , n))  return true ;
        }

        res[i][j] = 0 ;

        return false ;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix)
	{
        int n = matrix.size() ;
        vector<vector<int>>res(n,vector<int>(n,0)) ;
        vector<vector<int>>ans(1);
        
        ans[0].push_back(-1) ;
        if(matrix[0][0] == 0 && n>1)  return ans ;
        if(findPath(matrix,res,0,0,n)) return res ;
        
        return ans ;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends