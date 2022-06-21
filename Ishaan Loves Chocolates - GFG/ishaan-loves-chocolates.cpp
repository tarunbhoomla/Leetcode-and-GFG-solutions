// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int chocolates(int arr[], int n);


int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        cout << chocolates(arr, n);
        cout << endl;
        
    }

}
// } Driver Code Ends


int chocolates(int arr[], int n)
{
    int start = 0 ;
    int end = n-1 ;
    
    while(start<end)
    {
        if(arr[start] >= arr[end])
           start++ ;
        else
          end-- ;
    }
    
    return arr[start] ;
}
