class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string>st ;
        for(int i=0 ;i<s.size() ;i++)
        {
            if(s[i]==' ')
                continue ;
            string temp = "" ;
            while(i<s.size())
            { 
                if(i>=s.size() || s[i]==' ')
                    break ;
                
                temp+=s[i] ;
                i++ ;
            }
            
            st.push(temp) ;
        }
        string res="" ;
        while(!st.empty())
        {
            string temp = st.top() ;
            st.pop() ;
            
            res += temp ;
            res +=" ";
        }
        res.pop_back() ;
        
        return res ;
    }
};