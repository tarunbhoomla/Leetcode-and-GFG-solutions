class Solution {
public:
    int fun(vector<int>&nums ,int n ,int curr ,vector<vector<int>>&dp)
    {
        if(n<0)
            return 0 ;

        if(dp[n][curr+1] != -1)
            return dp[n][curr+1] ;
        
        int take = 0 ;
        int dontake = 0 ;

        if(curr == -1 || nums[curr] > nums[n])
        {
            take = 1 + fun(nums ,n-1 , n ,dp) ;
        }
         dontake = fun(nums ,n-1 , curr ,dp) ;

        return dp[n][curr+1] = max(take ,dontake) ;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<vector<int>> dp(n+1 ,vector<int>(n+1 , -1)) ;
        int curr = -1 ;
        return fun(nums,n-1 ,curr ,dp) ;
    }
};