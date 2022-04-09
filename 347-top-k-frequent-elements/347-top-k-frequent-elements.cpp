class Solution
{
public:
    vector<int> topKFrequent(vector<int> &arr, int k)
    {
        int n = arr.size();
        // if k is equal to n than we will pick all elements
        // because in this case count of all element is one.
        if (k == n)
            return arr;

        // sorting the arr
        sort(arr.begin(), arr.end());

        // storing (cnt,val) in a vector(pair)
        vector<pair<int, int>> vp;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
                vp.push_back({cnt, arr[i - 1]}),
                    cnt = 1;
            else
                cnt++;
        }
        vp.push_back({cnt, arr[n - 1]});

        // sorting vector(pair) according to first value
        sort(vp.begin(), vp.end());

        // inserting first k elements in ans vector
        vector<int> ans;
        int i = vp.size() - 1;
        while (k--)
            ans.push_back(vp[i].second),
                i--;

        return ans;
    }
};