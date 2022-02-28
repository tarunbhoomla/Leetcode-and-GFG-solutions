// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void rec(int a[] ,int N ,int curr ,string temp ,vector<string>&res,
                     string buttons[])
    {
        if(curr==N)
          {
              res.push_back(temp) ;
              return ;
          }
          
        string str = buttons[a[curr]] ;
        for(int i=0 ;i<str.size() ;i++)
        {
            rec(a , N ,curr+1 ,temp+str[i] ,res ,buttons) ;
        }
    }
    vector<string> possibleWords(int a[], int N)
    {   vector<string> res ;
        string buttons[10]  = {"" ,"" ,"abc" ,"def" ,"ghi" ,"jkl" ,"mno",
                               "pqrs" ,"tuv" ,"wxyz" } ;
        
        if(N==0)
          return res ;
        
        
        rec(a , N , 0 ,"" ,res , buttons) ;
        
        return res ;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends