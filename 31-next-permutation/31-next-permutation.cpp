class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int temp1 ;
        int n = nums.size()-1 ;
        bool flag = false ;
        for(int i=n-1 ;i>=0 ;i--)
        {
            if(nums[i] < nums[i+1])
            {
                flag = true ;
                temp1 = i ;
                break ;
            }
        }
        if(flag==false)
        {
            reverse(nums.begin() ,nums.end()) ;
            return ;
        }
        int minG = INT_MAX ;
        for(int i=n ;i> temp1 ;i--)
        {
            if(nums[i]>nums[temp1])
            {
                minG = min(minG , nums[i]) ;
            }
        }
        int temp2 ;
        for(int i=0 ;i<=n ;i++)
        {
            if(nums[i]==minG)
                 temp2 = i ;
        }
        swap(nums[temp1] , nums[temp2]) ;
        reverse(nums.begin()+temp1+1 , nums.end()) ;
        
        
    }
};