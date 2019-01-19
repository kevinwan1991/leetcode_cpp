int lower_bound(const std::vector<int>& nums, int target) 
{
    int l = 0, r = nums.size()-1;
    while (l <= r) 
    {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
int upper_bound(const std::vector<int>& nums, int target)
{
    int left = 0 , right = nums.size() ; 
    while(left < right)
    {
        int mid = (right - left) / 2 + left ;
        if(nums[mid] > target) 
            right = mid ;
        else 
            left = mid + 1; 
    }
    return left;
}
