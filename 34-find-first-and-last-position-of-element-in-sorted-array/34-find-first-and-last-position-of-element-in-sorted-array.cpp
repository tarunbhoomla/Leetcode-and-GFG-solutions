class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {        
        int j=-1 ,k=-1 ;
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i]==target)
            {
                j=i ;
                break ;
            }
        }
        
        for(int i=nums.size()-1 ;i>=0 ;i--)
        {
            if(nums[i]==target)
            {
                k=i ;
                break; 
            }
        }
        
        return {j,k} ;
    }
};