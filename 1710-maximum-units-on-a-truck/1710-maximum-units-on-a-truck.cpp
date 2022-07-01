class Solution {
public:
    static bool myComp(vector<int>x , vector<int> y )
    {
        return x[1] > y[1] ;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int res = 0 ;
        sort(boxTypes.begin() , boxTypes.end() , myComp) ;
        int i=0 ;
        for(i=0 ;i<boxTypes.size() ; i++)
        {
            if(boxTypes[i][0] <= truckSize)
            {
                res += boxTypes[i][0] * boxTypes[i][1] ;
                truckSize -= boxTypes[i][0] ;
            }
            else{
                res += truckSize * boxTypes[i][1];
                break ;
            }
        }
        
        return res ;
    }
};