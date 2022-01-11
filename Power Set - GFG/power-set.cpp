// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s)
		{
		    vector<string> res ;
		    int n = pow(2,s.size()) ;
		    
		    for(int i=1 ;i<n ;i++)
		    {
		        int x = i ;
		        int j = 0 ;
		        string str="" ;
		        while(x>0)
		        {
		            if(x&1)
		            {
		                str = str+s[j] ;
		            }
		            j++ ;
		            x=x>>1 ;
		            
		        }
		        res.push_back(str) ;
		    }
		    sort(res.begin() , res.end()) ;
		    return res ;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends