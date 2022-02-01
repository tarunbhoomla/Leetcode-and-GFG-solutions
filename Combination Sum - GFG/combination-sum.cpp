// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void combinationSum(vector<int> &A, int B, vector< vector<int> >& combinations, vector<int>& curr_combs, int curr_sum, int idx) {
        if (curr_sum > B) {
            return;
        }
        
        if (curr_sum == B) {
            combinations.push_back(curr_combs);
            return;
        }
        
        for (int i = idx; i < A.size(); ++i) {
            if (!curr_combs.empty() && A[i] < curr_combs.back()) {
                continue;
            }
            
            curr_combs.push_back(A[i]);
            combinationSum(A, B, combinations, curr_combs, curr_sum + A[i], i);   
            curr_combs.pop_back();
        }
    }
  
    vector< vector<int> > combinationSum(vector<int> &A, int B) 
    {
        sort(A.begin(), A.end());
        vector<int> A_no_dups;
        for (int i = 0; i < A.size(); ++i) 
        {
            if (i > 0 && A[i] == A[i-1]) 
                continue;
            
            A_no_dups.push_back(A[i]);
        }
        vector<vector<int>> res;
        vector<int> curr_combs;
        set<vector<int>> tried;
        combinationSum(A_no_dups,B,res,curr_combs,0,0);

        return res;
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends