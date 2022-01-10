// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:

    vector<int> singleNumber(vector<int> nums) 
    {
        int x = 0 ;
        for(int i = 0 ; i<nums.size() ;i++)
        {
            x = x^nums[i] ;                       // x = 1^3
        }
        
        int setBitX = 0 ;
        int temp = x , temp2 = x ;
        while(temp>0)
        {
            if(temp & 1)
            {
                break ;
            }
            else
            {
                setBitX++ ;
                temp = temp>>1 ;
            }
        }
        int m = 1<<setBitX ;

        for(int i=0 ; i<nums.size() ;i++)
        {
            if(m & nums[i])
            {
                x = x^nums[i] ;
            }
        }
        
        temp2 = temp2^x ;
        
        vector<int>res ;
        res.push_back(x) ;
        res.push_back(temp2) ;
        
        sort(res.begin() , res.end()) ;
        
        
        return res ;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends