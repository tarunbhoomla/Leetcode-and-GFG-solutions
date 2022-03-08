class Solution {
public:
    bool isValid(string s) 
    {

        if(s.length()%2 != 0){
            return false;
        }
        
        stack<char>st ;
        st.push(s[0]);
        for(int i=1 ;i<s.size() ;i++)
        {
        if(st.empty())
            st.push(s[i]) ;
        else  if(( st.top()=='(' && s[i]==')') 
            || (st.top()=='{' && s[i]=='}') 
            || (st.top()=='[' && s[i]==']') )
                st.pop() ;
            else
                st.push(s[i]) ;
        }
        
        if(st.empty())
              return true ;
        else
              return false;
    }
};