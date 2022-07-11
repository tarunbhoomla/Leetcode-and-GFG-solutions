class Solution {
public:
    static bool myComp(pair<string,int>a ,pair<string,int>b)
    {
			return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> s ;
        for(auto it:words)
        {
            s[it]++;
        }
        
        vector<pair<string,int>> vec ;
        for(auto it:s)
        {
            vec.push_back({it.first,it.second}) ;
        }
        
        sort(vec.begin() ,vec.end() ,myComp) ;

        vector<string> res ;

		for(int i = 0; i < k; i++){
			res.push_back(vec[i].first);
		}
        
        return res ;
        
    }
};