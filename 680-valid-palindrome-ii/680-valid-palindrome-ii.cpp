class Solution {
public:
    bool checkPal(string str)
    {
        int l = 0 ;
        int h = str.size()-1 ;
        while(l<=h)
        {
            if(str[l]==str[h])
            {
                l++ ;
                h-- ;
            }
            else
                return false ;
        }
        
        return true ;
    }
    bool validPalindrome(string s) 
    { 
        int l = 0 ;
        int h = s.size()-1 ;
        
        while(l<=h)
        {
               if(s[l]==s[h])
               {
                   l++ ;
                   h-- ;
               }
               else
               {
                    string str1 = s ;
                    string str2 = s ;
                    str1.erase(str1.begin()+l) ;
                    str2.erase(str2.begin()+h) ;
                       if(checkPal(str1) || checkPal(str2) )
                          {
                              return true ;
                          }
                       else
                          return false ;
                          
                   }
              }
        
        return true ;
    }
};