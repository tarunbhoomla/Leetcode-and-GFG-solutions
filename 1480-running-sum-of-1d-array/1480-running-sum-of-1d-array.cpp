class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> res ;
        int curr = 0 ;
        for(int i=0 ;i<nums.size() ;i++)
        {
            curr += nums[i] ;
            res.push_back(curr) ;
        }
        
        return res ;
    }
};