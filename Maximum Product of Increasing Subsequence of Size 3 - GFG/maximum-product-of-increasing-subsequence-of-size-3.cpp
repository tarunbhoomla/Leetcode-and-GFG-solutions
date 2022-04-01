// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        vector<int>ans{-1,-1,-1},maxi;
        for(int i=0;i<n;i++)maxi.push_back(arr[i]);
        for(int i=n-2;i>=0;i--)maxi[i]=max(maxi[i],maxi[i+1]);
        
        set<int>s;
        
        for(int i=1;i<n-1;i++){
            s.insert(arr[i-1]);
            auto itr = s.lower_bound(arr[i]);
            if(itr!=s.begin() and arr[i]<maxi[i+1]){
                itr--;
                long long int cur=1ll*(*itr)*arr[i]*maxi[i+1];
                long long int old=1ll*ans[0]*ans[1]*ans[2];
                if(old<cur){
                    ans={*itr,arr[i],maxi[i+1]};
                }
            }
        }
        return ans;
    }

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends