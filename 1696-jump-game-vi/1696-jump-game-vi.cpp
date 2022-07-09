class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n= nums.size();
        
        // priority queue stores the maximum possible score we could get 
        // while starting from index i
        // we will start from right to left and for every starting index=i
        // we will try to find the maximum possible jump within the range( this
        // is found out using the priority queue, as it is a max heap)
        priority_queue<pair<int, int>> pq;
        pq.push({nums[n-1], n-1});
        
        
        // ans at last will store the maximum possible score achieved when starting
        // at index =0, in case of 1 element, ans = nums[0], right! so i initialised 
        // ans with nums[n-1] and not with random values
        int i=n-2, ans=nums[n-1];
        while(i>=0){
            
            //  for current index=i, we will ist add our value,i.e, nums[i]
            // to the current score
            int curr_score= nums[i];
            
            // and then while the maximum values are out of range(that is, difference
            // between (i and max_score_to_right's index) is > k)
            // keep popping 
            while( (pq.top().second - i)>k)
                pq.pop();
               
            // after this add the value at the max. idx , where we could jump;
            // to the current score as well
            curr_score+= pq.top().first;
            pq.push({curr_score, i});
            
            // this is the answer we will return , becoz we have to start our jumps from
            // index =0
            if( !i)
                ans= curr_score;
            i--;
            
        }
        
        return ans;
    }
};