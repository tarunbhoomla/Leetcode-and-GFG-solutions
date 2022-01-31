// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void helper(int open , int close ,vector<string>&res , string &temp)
    {
        if(open==0 && close==0)
        {
            res.push_back(temp) ;
            return ;
        }
        
        if(open>0)
        {
            string x = temp +'(' ;
            helper(open-1 , close ,res ,x) ;
        }
        
        if(close > open)
        {
            string y = temp +')' ;
            helper(open ,close-1 ,res ,y) ;
        }
    }
    vector<string> AllParenthesis(int n) 
    {
         vector<string> res ;
         string str ="" ;
         int open = n ;
         int close = n ;
         
         helper(open, close, res ,str) ;
         
         return res ;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends