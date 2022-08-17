class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        unordered_map<string,int> res ;
        vector<string>temp = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",
                               ".---","-.-",".-..","--","-.","---",".--.","--.-",".-."
                               ,"...","-","..-","...-",".--","-..-","-.--","--.." };
        for(int i=0 ;i<words.size() ;i++)
        {
            string str = words[i] ;
            string toPush = "" ;
            for(int j=0 ;j<str.size() ;j++)
            {
                toPush += temp[str[j]-'a'] ;
            }

            res[toPush]++ ;
        }

        return res.size() ;
    }
};