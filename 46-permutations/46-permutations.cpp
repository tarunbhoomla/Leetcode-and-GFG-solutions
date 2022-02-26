class Solution {
public:
    void recursive(vector<int>&nums,int idx ,int n,vector<vector<int>> &res)
    {
        if(idx==n)
        {
            res.push_back(nums) ;
            return ;
        }
        for(int i=idx ; i<n ;i++)
        {
            swap(nums[idx] ,nums[i]) ;
            recursive(nums,idx+1,n, res) ;
            swap(nums[idx],nums[i]) ;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<vector<int>> res ;
        
        recursive(nums , 0 , n , res ) ;
        
        return res ;
    }
};