class Solution {
public:
    bool fun(vector<int>&nums ,int n , int sum , vector<vector<int>>&dp)
    {
        if(n<0 && sum != 0)
            return false;
        if(sum<0)
            return false ;
        if(sum==0)
            return true ;
        
        if(dp[n][sum] != -1)
            return dp[n][sum] ;
        
        return dp[n][sum] = fun(nums ,n-1 ,sum-nums[n] ,dp)  || fun(nums ,n-1 ,sum ,dp) ;

    }
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size() ;
        
        int sum=0;
        for(auto i:nums) sum+=i;
        
        if(sum%2==1) return false;
        vector<vector<int>> dp(n ,vector<int>(sum/2+1 , -1)) ;
        return fun(nums ,n-1,sum/2 , dp) ;
    }
};