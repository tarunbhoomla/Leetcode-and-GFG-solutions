class Solution {
public:
    void recursive(vector<int>&nums,int idx ,int n,set<vector<int>> &res)
    {
        if(idx==n)
        {
            res.insert(nums) ;
            return ;
        }
        for(int i=idx ; i<n ;i++)
        {
            swap(nums[idx] ,nums[i]) ;
            recursive(nums,idx+1,n, res) ;
            swap(nums[idx],nums[i]) ;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {

        int n = nums.size() ;
        set<vector<int>> res ;

        recursive(nums , 0 , n , res ) ;
        
        vector<vector<int>>res2 ;
        
        for(auto it:res)
        {
            res2.push_back(it) ;
        }
        return res2 ;
    }
};