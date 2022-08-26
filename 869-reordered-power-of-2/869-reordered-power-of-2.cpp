class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string str = to_string(n) ;
        sort(str.begin() ,str.end()) ;
        
        unordered_set<string> mp ;

        for(int i=0 ;i<=30 ;i++)
        {
            int x = pow(2,i) ;
            string temp = to_string(x) ;
            sort(temp.begin() ,temp.end()) ;
            
            mp.insert(temp) ;
        }
        
       if(mp.find(str) !=  mp.end())
           return true ;
        else
            return false ;
    }
};