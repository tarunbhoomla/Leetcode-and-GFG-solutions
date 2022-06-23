// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[]){
       vector<long long >ans;
       ans.push_back(S);
       long long pre=S;
       for(int i =0;i<N;i++){
            long long cur;
            cur=A[i]+pre;
          ans.push_back(cur);
            pre+=cur;
           if(pre>X)
        break;
           
           }
           for(int i=ans.size()-1;i>=0;i--){
                    if(ans[i]<=X){
                        X-=ans[i];
                        
                    }   
                    if(X==0)
                    return 1;
                        
                    
                    
                    }return 0;
           }
        
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends