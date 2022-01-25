// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
string findOrder(string dict[], int N, int k) {
        map<char,vector<char>> m;
        int count[k]={0};
        
      for(int i=1;i<N;i++)
      {
          for(int j=0;j<dict[i].length() && j<dict[i-1].length() ;j++)
          { 
              if(dict[i-1][j]==dict[i][j])
              continue;
              
              else
              {
                  char as=dict[i-1][j],bs=dict[i][j];
                  m[as].push_back(bs);
                  break;
              }
          }
      }
          
          for(int i=0;i<k;i++)
          {
              for(auto ch : m[i+'a'])
              {
                  count[ch-'a']++;
              }
              
          }
          
          queue<char> q;
          
          for(int i=0;i<k;i++)
          {
              if(count[i]==0)
              {
                  q.push('a'+i);
              }
          }
          
          string s="";
          
          while(!q.empty())
          {
              char tp= q.front();
              q.pop();
              for(auto ch : m[tp])
              {
                  count[ch-'a']--;
                  if(count[ch-'a']==0)
                  q.push(ch);
              }
              s+=tp;
          }
          
         return s; 
      }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends