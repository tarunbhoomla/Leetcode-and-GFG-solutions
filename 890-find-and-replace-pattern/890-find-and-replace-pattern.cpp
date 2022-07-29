class Solution {
public:
    bool checkPattern(string str , string pattern)
    {
        if(str.size() != pattern.size())
             return false ;
        
        unordered_map<char ,int> mp ,mp2 ;
        for(int i=0 ;i<str.size() ;i++)
        {
            if(mp.find(str[i])!= mp.end() || mp2.find(pattern[i]) != mp2.end())
               if(mp[str[i]] != mp2[pattern[i]])
                   return false ;
            
            mp[str[i]] = i+1 ;
            mp2[pattern[i]] = i+1 ;
        }
        
        return true ;

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> res ;
        for(string str : words)
        {
            if(checkPattern(str , pattern))
                res.push_back(str) ;
        }
        
        return res ;
    }
};