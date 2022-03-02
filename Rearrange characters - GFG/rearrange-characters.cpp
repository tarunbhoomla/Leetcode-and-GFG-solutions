// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
string rearrangeString(string str)
    {
        //code here
        priority_queue<pair<int,char>> pq;

        //priority_queue<int> g;
        map<char, int > mp;
        int n=str.size();
        for( int i=0;i<n;i++)
        mp[str[i]]++;

        for(auto itr:mp)
        {
            pq.push(make_pair(itr.second, itr.first));
        }
        string s="";
        int k=0;

        while(!pq.empty())
        {
           pair<int, char > g=pq.top();

           pq.pop();
           pair<int, char > h=make_pair(-1,'.');
           if(s!="" && g.second == s[k-1])
           {
               h=g;
               g=pq.top();
               pq.pop();
           }
           s+=g.second;
           //cout<<g.second<<" ";
           k++;
           g.first-=1;
           if(h!=make_pair(-1,'.'))
           {
              pq.push(h);
           }
           if(g.first>0 && pq.empty()==true )
           {
               return "-1";
           }
           if(g.first>0){
           pq.push(g);
           }
        }

        return s;
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends