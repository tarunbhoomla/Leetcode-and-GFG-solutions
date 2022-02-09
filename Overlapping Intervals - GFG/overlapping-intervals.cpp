// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
    {
    //      int maxEl = INT_MIN ;
    //      for(int i=0 ;i<intervals.size() ;i++)
    //      {
    //          maxEl = max(maxEl , intervals[i][1]) ;
    //      }
         
    //      vector<int> arr (maxEl , 0) ;
    //      for(int i=0 ;i<intervals.size() ;i++)
    //      {
    //          int start = intervals[i][0] ;
    //          int end   = intervals[i][1] ;
    //          for(int i=start ;i<=end ;i++)
    //          {
    //              arr[i]++ ;
    //          }
    //      }
         
    //      vector<vector<int>> res ;
    //      for(int i=1 ;i<=maxEl ;i++)
    //      {
    //          if(arr[i] > 0)
    //           {
    //               int start1 = arr[i] ;
    //               while(arr[i]>0) i++ ;
    //               int end1 = arr[i-1] ;
    //               i-- ;
    //               res.push_back({start1 ,end1}) ;
    //           }
    //          else
    //           i++ ;
    //      }
         
    //      return res ;
    // }
    
         sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;

         int n= intervals.size();
         if(n==0) return ans;
         if(n==1) return intervals;
         int f=intervals[0][0];
         int s= intervals[0][1];
         for(int i=1;i<n;i++)
         {
             if(intervals[i][0]>=f && intervals[i][0]<=s)
             {
                 if(s<intervals[i][1])
                 {
                     s=intervals[i][1];
                 }
             }else{
                 vector<int> k;
                 k.push_back(f);
                 k.push_back(s);
                 ans.push_back(k);
                 f=intervals[i][0];
                 s=intervals[i][1];
             }
         }


          vector<int> k;
                 k.push_back(f);
                 k.push_back(s);
                 ans.push_back(k);

                 return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends