class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        sort(horizontalCuts.begin() , horizontalCuts.end()) ;
        sort(verticalCuts.begin() , verticalCuts.end()) ;
        
        int maxHorizontal = max(horizontalCuts[0]-0  ,h-horizontalCuts[horizontalCuts.size()-1]) ;
    int maxVertical = max(verticalCuts[0]-0  , w-verticalCuts[verticalCuts.size()-1]) ;
        
        for(int i=1 ;i<horizontalCuts.size() ; i++)
        {
            int cut = horizontalCuts[i]-horizontalCuts[i-1] ;
            if(cut > maxHorizontal)
                 maxHorizontal = cut ;
        }
        
        for(int i=1 ;i<verticalCuts.size() ; i++)
        {
            int cut = verticalCuts[i]-verticalCuts[i-1] ;
            if(cut > maxVertical)
                 maxVertical = cut ;
        }
        maxVertical %= mod ;
        maxHorizontal %= mod ;
        return (1LL*maxHorizontal*maxVertical) % 1000000007;
        
    }
};