class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> um ;
        for(int i=0 ;i<nums.size();i++)
        {
            um[nums[i]] = i ;
        }
        
        int x = -22 ;
        int y = -22 ;
        
        for(int i=0 ;i<nums.size() ;i++)
        {
            int num2 = target - nums[i] ;
            if(um.find(num2) != um.end())
            {
                 x = i ;
                 y = um[num2] ;
                 if(x==y)
                     continue ;
                 break ;
                 
            }
        }
        
        return {x,y} ;
    }
};