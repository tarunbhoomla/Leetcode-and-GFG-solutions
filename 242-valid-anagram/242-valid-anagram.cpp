class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int n = s.size() ;
        int m = t.size() ;
        
        if(n!=m)
            return false ;
        
        vector<int> x (26,0) ;
        vector<int> y (26,0) ;
        
        for(int i=0 ;i<n ;i++)
        {
            x[s[i]-'a']++ ;
            y[t[i]-'a']++ ;
        }
        
        if(x!=y)
             return false;
    
        
        return true ;
    }
};