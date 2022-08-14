class Solution {
public:
    int fun(vector<int>&nums ,int n, vector<int>&dp)
    {
        if(n<0)
            return 0 ;
        
        if(dp[n] != -1)
            return dp[n] ;
        int take = fun(nums , n-2 ,dp) + nums[n] ;
        int notake = fun(nums ,n-1 ,dp) ;
        
        return dp[n] = max(take, notake) ;
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<int>dp(n ,-1) ;
        return fun(nums , n-1 ,dp) ;
    }
};