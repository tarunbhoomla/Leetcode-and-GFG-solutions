class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {        
//         int j=-1 ,k=-1 ;
//         for(int i=0 ;i<nums.size() ;i++)
//         {
//             if(nums[i]==target)
//             {
//                 j=i ;
//                 break ;
//             }
//         }
        
//         for(int i=nums.size()-1 ;i>=0 ;i--)
//         {
//             if(nums[i]==target)
//             {
//                 k=i ;
//                 break; 
//             }
//         }
        
//         return {j,k} ;
        
        int l=0 , h=nums.size()-1 ;
        int first=-1 ,last=-1 ;
        while(l<=h)
        {
            int mid = l+(h-l)/2 ;
            
            if((nums[mid]==target && mid==0) || nums[mid]==target && nums[mid-1]!=target)
            {
                first = mid ;
                break ;
            } 
            
            if(nums[mid] < target)
                l = mid+1 ;
            else if(nums[mid] > target || nums[mid]==target)
                h = mid-1 ;   
        }

        l=0 , h=nums.size()-1 ;
        while(l<=h)
        {
            int mid = l+(h-l)/2 ;
            
            if((nums[mid]==target && mid==nums.size()-1) || nums[mid]==target && nums[mid+1]!=target)
            {
                last = mid ;
                break ;
            } 
            
            if(nums[mid] < target || nums[mid]==target)
                l = mid+1 ;
            else if(nums[mid] > target)
                h = mid-1 ;   
        }
        
        return {first,last} ;
    }
};