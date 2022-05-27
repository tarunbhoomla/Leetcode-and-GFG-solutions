class Solution {
public:
    
    vector<string> rec(int n)
    {
        if(n==1)
            return {"0" ,"1"} ;
        
        vector<string>v = rec(n-1) ;
        vector<string>res ;
        
        
        for(int i=0 ;i<v.size() ;i++)
        {
            res.push_back('0' + v[i]) ;
        }
        
        for(int i=v.size()-1 ; i>=0 ;i--)
        {
            res.push_back('1' + v[i]) ;
        }
        
        return res ;
    }
    vector<int> grayCode(int n) 
    {
        
        vector<int> ans ;
        vector<string> temp ;
        temp = rec(n) ;
        
        for(int i=0 ; i<temp.size() ;i++)
             ans.push_back(stoi(temp[i] ,0,2)) ;
        return ans ;
    }
};