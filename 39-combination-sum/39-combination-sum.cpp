class Solution {
public:
//     void recursive(vector<int>&candidates ,int target , vector<int>temp,
//                   vector<vector<int>>&res)
//     {
//         if(target==0)
//         {
//             res.push_back(temp) ;
//             return ;
//         }
//         else
//         {
//             for(int i=0 ;i<candidates.size() ; i++)
//             {
//               temp.push_back(candidates[i]) ;
//               recursive(candidates ,target-candidates[i] , temp , res ) ;
//               temp.pop_back() ;        
//             }
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
//     {

//         vector<int> temp ;

//         candidates.erase(unique(candidates.begin(),candidates.end())
//                          ,candidates.end() );

//         vector<vector<int>> res ;
//         recursive(candidates,target , temp , res ) ;

//         return res ;
//     }
    
    
void rec(int i , int n , int target  , vector<int> v, vector<vector<int>> &ans,vector<int>& c )
    {
        if(target<0) return ;
      
        if(i==n)
        {
            if(target==0)
                ans.push_back(v);  
             return;
        }
        v.push_back(c[i]);
        rec(i, n, target-c[i], v, ans, c );
        v.pop_back();
        rec(i+1, n, target, v, ans, c);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> v;
        vector<vector<int>> ans;
        int n=candidates.size();
        rec(0,n,target,v,ans,candidates );
        return ans;
    }
};