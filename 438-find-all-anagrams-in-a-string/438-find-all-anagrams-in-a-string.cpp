class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n1 = s.size() ;
        int n2 = p.size() ;
        
        vector<int>temp(26,0) ;
        vector<int>temp2(26,0) ;
        
        vector<int>res ;
        
        if(n1 < n2)
            return res ;
        
        for(int i=0 ;i<n2 ;i++){
            temp2[p[i]-'a']++ ;
            temp[s[i]-'a']++ ;
        }
        
        int l = 0 , h=n2-1 ;      
        while(h<n1)
        {
            if(temp == temp2)
            {
                res.push_back(l) ;
            }
            h++ ;
            if(h!=n1)
            {
                temp[s[l]-'a'] -= 1 ;
                l++;
                temp[s[h]-'a'] += 1 ;
            }

        }
        
        return res ;
        
    }
};