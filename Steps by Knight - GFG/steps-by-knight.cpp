// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&a, vector<int>&b, int n)
	{
	    // Code here
	    int x1 = a[0], y1 = a[1];
	    int x2 = b[0], y2 = b[1];
	    int dp[n][n];
	    memset(dp,0,sizeof(dp));
	    queue<pair<int,int>>q;
	    q.push({x1-1,y1-1});
	    while(!q.empty()){
	        int i = q.front().first, j = q.front().second;
	        q.pop();
	        if(i+2 >= 0 and i+2 < n and j-1 >= 0 and j-1 < n and dp[i+2][j-1] == 0){
	            dp[i+2][j-1] = dp[i][j] + 1;
	            q.push({i+2,j-1});
	        }
	        if(i+2 >= 0 and i+2 < n and j+1 >= 0 and j+1 < n and dp[i+2][j+1] == 0){
	            dp[i+2][j+1] = dp[i][j] + 1;
	            q.push({i+2,j+1});
	        }
	        if(i-2 >= 0 and i-2 < n and j+1 >= 0 and j+1 < n and dp[i-2][j+1] == 0){
	            dp[i-2][j+1] = dp[i][j] + 1;
	            q.push({i-2,j+1});
	        }
	        if(i-2 >= 0 and i-2 < n and j-1 >= 0 and j-1 < n and dp[i-2][j-1] == 0){
	            dp[i-2][j-1] = dp[i][j] + 1;
	            q.push({i-2,j-1});
	        }
	        if(i-1 >= 0 and i-1 < n and j-2 >= 0 and j-2 < n and dp[i-1][j-2] == 0){
	            dp[i-1][j-2] = dp[i][j] + 1;
	            q.push({i-1,j-2});
	        }
	        if(i-1 >= 0 and i-1 < n and j+2 >= 0 and j+2 < n and dp[i-1][j+2] == 0){
	            dp[i-1][j+2] = dp[i][j] + 1;
	            q.push({i-1,j+2});
	        }
	        if(i+1 >= 0 and i+1 < n and j-2 >= 0 and j-2 < n and dp[i+1][j-2] == 0){
	            dp[i+1][j-2] = dp[i][j] + 1;
	            q.push({i+1,j-2});
	        }
	        if(i+1 >= 0 and i+1 < n and j+2 >= 0 and j+2 < n and dp[i+1][j+2] == 0){
	            dp[i+1][j+2] = dp[i][j] + 1;
	            q.push({i+1,j+2});
	        }
	    }
	    return dp[x2-1][y2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends