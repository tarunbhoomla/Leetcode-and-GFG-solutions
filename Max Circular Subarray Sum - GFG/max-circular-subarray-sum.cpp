// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadance(int arr[] , int n)
    {
        int curr=0 ;
        int maxi = INT_MIN ;
        
        for(int i=0 ;i<n ;i++)
        {
            curr += arr[i] ;
            if(curr > maxi)
            maxi = max(maxi,curr) ;
            if(curr <= 0)
              curr = 0 ;
        }
        
        return maxi ;
    }
    int circularSubarraySum(int arr[], int n)
    {
        int x = kadance(arr,n) ;
        
        int tot = 0 ;
        int maxi = INT_MIN ;
        for(int i=0 ;i<n ;i++)
        {
           if(arr[i] > maxi)
             maxi = arr[i] ;
           tot = tot+arr[i] ;           
        }

         
        
        for(int i=0 ;i<n ;i++)
          arr[i] = -arr[i] ;
        
        int nonCir = kadance(arr,n) ;
        for(int i=0 ;i<n ;i++)
          arr[i] = -arr[i] ;
        int res = max(x,tot + nonCir) ;
        if(res==0){
            for(int i=0 ;i<n ;i++)
            {
                if(arr[i]==0)
                  return 0 ;
                else
                 {
                     return maxi ;
                 }
            }
        }
        return res ;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends