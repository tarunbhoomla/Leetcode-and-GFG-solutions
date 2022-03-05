class Solution {
public:
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, h = n - 1 ;
    int m ;

    while (l <= h)
    {
        m = (l + h) / 2;
        if (nums[m] > nums[(m + 1) % n])    
             break;
        else if (nums[m] < nums[l]) 
                h = m - 1;
             else    
                l = m + 1;
    }

    l = m + 1, h = n - 1;
    if (nums[0] <= target)
    {
        l = 0;
        h = m;
    }

    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (nums[m] == target)  return m;
        else if (nums[m] < target)  l = m + 1;
        else    h = m - 1;
    }

    return -1;
}
};