// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void rec(vector<int> arr , int i, int n , vector<int>temp , 
                      set<vector<int>> &um)
    {
        if(i==n)
        {
            sort(temp.begin() , temp.end()) ;
            um.insert(temp) ;
            return ;
        }
        rec(arr, i+1 , n , temp , um) ;
        temp.push_back(arr[i]) ;
        rec(arr, i+1 , n , temp , um) ;
        
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>> us ;
        vector<int> temp ;
        rec(arr , 0 , n ,temp , us) ;
        
        vector<vector<int>> res ;
        for(auto it: us)
        {
            res.push_back(it) ;
        }
        sort(res.begin() , res.end()) ;
        
        return res ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends