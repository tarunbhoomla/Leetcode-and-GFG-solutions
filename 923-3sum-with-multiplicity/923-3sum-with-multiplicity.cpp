
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        long long int ans=0;
        long long mod=1e9+7;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=(ans+mp[target-arr[i]-arr[j]])%mod;
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};