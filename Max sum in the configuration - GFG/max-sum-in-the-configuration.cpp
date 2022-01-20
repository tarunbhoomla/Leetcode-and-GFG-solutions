// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int sum1=0 , sum2= 0  ;
    for(int i=0 ;i<N ;i++)
    {
        sum1 += A[i] ;
        sum2 += i*A[i] ;
    }
    int res = INT_MIN ;
    for(int i=0 ; i<N ; i++)
    {
        sum2 = sum2 + sum1 - N*(A[N-i-1]) ;
        res = max(res , sum2) ;
    }
    
    return res ;
}