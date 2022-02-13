class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int x = nums[0] ;
        int y = INT_MIN ;
        int count1 = 1 ;
        int count2 = 0 ;
        
        for(int i=1 ;i<nums.size() ;i++)
        {
            if (nums[i] == x )
                  count1++;
            else if(nums[i]==y)
                   count2++ ;
            else if(count1==0)
            {
                x = nums[i] ;
                count1++ ;
            }
            else if(count2==0)
            {
                y= nums[i] ;
                count2++ ;
            }
            
            else
            {
                count1-- ;
                count2-- ;
            }
        }
        count1=0 ;
        count2=0 ;
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i]==x)  count1++ ;
            if(nums[i]==y)   count2++ ;
        }
        vector<int> res ;
        if(count1 > nums.size()/3)
              res.push_back(x) ;
        if(count2 > nums.size()/3)
              res.push_back(y) ;
        
        return res ;
    }
};