class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int minP = 1;
        int maxP = 1;
        int ans = INT_MIN;
        
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i]<0)
            {
                swap(maxP ,minP) ;
            }
            
            maxP = max(nums[i] ,maxP*nums[i]) ;
            minP = min(nums[i] ,minP*nums[i]) ;
            
            ans = max(ans ,maxP) ;
        }
        
        return ans ;
    }
};