class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res ;
        
        int len = words[0].size() ;
        int count = words.size() ;
        
        if(s.size() < len*count)
            return res ;
        
        for(int i=0 ;i<= s.size()-len*count ;i++)
        {
            unordered_map<string,int> mp ;
            for(int j=0 ;j<words.size();j++)
                mp[words[j]]++ ;

            int k ;
            for(k=0 ;k<count ;k++)
            {
                string temp = s.substr(i+k*len , len) ;
                if(mp.count(temp)==0)
                    break ;
                else if(mp[temp] != 0)
                    mp[temp]-- ;
                else
                    break ;
            }

            if(k==count)
                res.push_back(i) ;
        }

        return res ;
    }
};