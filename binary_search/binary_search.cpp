int lower_bound(const std::vector<int>& nums, int target) 
{
    // first element that greater than or equal to target
    int l = 0, r = nums.size()-1;
    while (l <= r) 
    {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1; 
        else
            r = mid-1; // nums[mid]==target doesn't mean mid is the first element matches target
    }
    return l;
}

int lower_bound(const std::vector<int>& nums, int target) 
{
    // first element that greater than or equal to target
    int l = 0, r = nums.size()-1;
    while (l < r) 
    {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1; // once num[lhs]==target, lhs will not move
        else
            r = mid; // even nums[rhs]==target, rhs will decrease to meet lower bound
    }
    return l;
}

int upper_bound(const std::vector<int>& nums, int target)
{
    // first element that greater than target
    int left = 0 , right = nums.size() ; 
    while(left < right)
    {
        int mid = (right - left) / 2 + left ;
        if (nums[mid] <= target)
            left = mid + 1; // nums[mid]==target, lhs will move until nums[lhs]>target
        else         
            right = mid ;
    }
    return left;
}
