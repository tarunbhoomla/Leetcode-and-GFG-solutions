// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int r=hospital.size();
        int c=hospital[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==2)
                q.push({i,j});
            }
        }
        q.push({-1,-1});
        int samay=0;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            if(i==-1 && j==-1 && q.size()==1){
                q.pop();
                break;
            }
            else if(i==-1 && j==-1 && q.size()>1)
            {
                q.pop();
                samay++;
                q.push({-1,-1});
            }
            else{
            if(i-1>=0 && hospital[i-1][j]==1)
            {
                hospital[i-1][j]=2;
                q.push({i-1,j});
            }
            if(i+1<r && hospital[i+1][j]==1)
            {
                hospital[i+1][j]=2;
                q.push({i+1,j});
            }
            if(j-1>=0 && hospital[i][j-1]==1)
            {
                hospital[i][j-1]=2;
                q.push({i,j-1});
            }
            if(j+1<c && hospital[i][j+1]==1)
            {
                hospital[i][j+1]=2;
                q.push({i,j+1});
            }
            q.pop();
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==1)
                return -1;
            }
        }
        return samay;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends