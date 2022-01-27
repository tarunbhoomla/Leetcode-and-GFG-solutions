// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int i=0;
        while(i<n){
            if(k>0){
                if(a[i]<0){
                    a[i]=-a[i];
                    k--;
                }
            }
            i++;
            
        }
        
        sort(a,a+n);
    
        while(k>0){
            a[0]=-a[0];
            k--;
        }
        long long int sum=0;
        for(int x=0;x<n;x++){
            sum+=a[x];
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends