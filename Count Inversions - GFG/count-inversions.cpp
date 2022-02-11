// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // long long int inversionCount(long long arr[], long long N)
    // {
    //     set<long long int> st ;
    //     long long int res = 0 ;
    //     for(long long int i=0 ;i<N ;i++)
    //     {
    //         st.insert(arr[i]) ;
    //     }
    //     for(long long int i=0 ; i<N ; i++)
    //     {  
    //             long long int k = arr[i];
    //             long long int Index = 0;
                
    //             for (long long int u : st) 
    //             {
    //                  if (u == k)
    //                          break ;
    //                 Index++;
    //             }
    //         res += Index ;
    //         st.erase(arr[i]);
    //     }

    //     return res ;
    // }
    long long res;
    void merge(long long arr[], long long l, long long m, long long r)
    {
      long long int n1 = m - l + 1;
      long long int n2 = r - m;
 
      long long int L[n1], R[n2];
 
      for (long long int i = 0; i < n1; i++)
           L[i] = arr[l+i];
      for (long long int j = 0; j < n2; j++)
           R[j] = arr[m+1+j];
 

    long long int i = 0;
    long long int j = 0;

    long long int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            res += n1-i ;
        }
        k++;
    }
 

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
    void mergeSort(long long arr[],long long int l,long long int r)
    {
     if(l>=r)
        return;

     long long int m =l+ (r-l)/2;
     mergeSort(arr,l,m);
     mergeSort(arr,m+1,r);
     merge(arr,l,m,r);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        res = 0 ;
        mergeSort(arr , 0 , N-1) ;
        return res ;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends