class Solution {
public:
void recursive(vector<int> nums,vector<vector<int>>&res,int i,vector<int> v)
{
    if(i>=nums.size())
    {
        sort(v.begin(),v.end());
        res.push_back(v);
        return ;
    }
    recursive(nums,res,i+1,v);
    v.push_back(nums[i]);
    recursive(nums,res,i+1,v);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> res;
    vector<int> v;
    recursive(nums,res,0,v);
    
    sort(res.begin() , res.end()) ;
    
    set<vector<int>> ans ;
    for(auto it:res)
         ans.insert(it) ;
    
    res.clear() ;
    for(auto it:ans)
          res.push_back(it) ;
    return res;
}
};