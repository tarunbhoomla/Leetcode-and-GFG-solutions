class Solution {
public:
    
    int fun(vector<int>&nums ,int target,vector<int>&dp)
    {
        
        if(target==0)
            return 1 ;
        
        if(dp[target] != -1)
            return dp[target] ;
        
        
        int res = 0 ;
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i] <= target)
               res+= fun(nums ,target-nums[i],dp) ;
        }
        
        return dp[target] = res ;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int>dp(target+1,-1) ;
        int n = nums.size() ;
        return fun(nums ,target,dp) ;
    }
};