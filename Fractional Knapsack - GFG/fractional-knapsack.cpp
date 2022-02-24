// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item x1 , Item x2)
    {
        return ((double)x1.value/(double)x1.weight) > ((double)x2.value/(double)x2.weight) ;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr+n , cmp) ;
        double profit = 0 ;
        for(int i=0 ;i<n ;i++)
        {
            if(W >= arr[i].weight)
            {
                profit += arr[i].value ;
                W -= arr[i].weight ;
            }
            else
            {
                profit +=(((double)arr[i].value/(double)arr[i].weight) * W) ;
                return profit;
            }
        }
        
        return profit ;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends