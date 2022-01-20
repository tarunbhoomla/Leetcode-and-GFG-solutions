// { Driver Code Starts

// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) 
{
    vector<pair<int,int>>res ;
    for(int i=1 ; i<n ;i++)
    {
        pair<int,int>temp ;
        if(price[i] > price[i-1])
        {
            temp.first = i-1 ;
            i++ ;
            while(price[i] >= price[i-1] && i<n)
            {
                i++ ;
            }
            i-- ;
            temp.second = i ;
            res.push_back(temp) ;
        }
        

    }
    int answer = 0 ;
    if(res.size()==0)
       cout<<"No Profit"<<endl ;
    else
    {
       for(int i=0 ; i<res.size() ;i++)
          cout<<"("<<res[i].first<<" "<<res[i].second<<") " ;
        cout<<endl ;
    }

}