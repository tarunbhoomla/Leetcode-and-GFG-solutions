class Solution {
public:
//     void fun(vector<int>&nums ,int curr , vector<vector<int>>&res)
//     {
//         if(curr==nums.size() )
//             res.push_back(nums) ;
//         for(int i=curr ;i < nums.size() ;i++)
//         {
//             swap(nums[i] ,nums[curr]) ;
//             fun(nums,curr+1 ,res) ;
//             swap(nums[i] ,nums[curr]) ;
//         }
//     }
//     void nextPermutation(vector<int>& nums) 
//     {
//         vector<vector<int>>res ;
//         fun(nums ,0 , res ) ;
//         sort(res.begin() ,res.end() ) ;
//         int n = res.size() ;
//         int pos ;
//         for(int i=0 ;i<n ;i++)
//         {
//             if(res[i] == nums)
//                   pos = i ;
//         }
//         if(pos == n-1)
//             nums = res[0] ;
//         else
//             nums = res[pos+1] ;
      
//     }
         void nextPermutation(vector<int>& nums) 
         {
             int pos1 = INT_MIN ;
             for(int i=nums.size()-2 ; i>=0 ;i--)
             {
                 if(nums[i] < nums[i+1]) 
                 {
                     pos1 = i ;
                     break ;
                 }
             }
             if(pos1 == INT_MIN)
             {
                 reverse(nums.begin(),nums.end()) ;
                 return ;
             }
             int n = nums.size() ;
              if(nums[n-1]>nums[n-2])
             { 
              swap(nums[n-1], nums[n-2]);
              return ;
             }
             
             int pos2 = INT_MIN ;
             for(int i=nums.size()-1 ;i>=0 ;i--)
             {
                 if(nums[i] > nums[pos1])
                 {
                     pos2 = i ;
                     break ;
                 }
             }
                   
             swap(nums[pos1] , nums[pos2]) ;
             
             sort(nums.begin()+pos1+1 , nums.end()) ;
             
         }
};