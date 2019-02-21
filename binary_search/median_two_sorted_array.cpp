    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int total = nums1.size()+nums2.size();
        if (total%2 == 1)
            return findKth(nums1,0,nums2,0,total/2+1);
        else
            return (findKth(nums1,0,nums2,0,total/2) + findKth(nums1,0,nums2,0,total/2+1))/2;
    }
    
    double findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
    {
        if (nums1.size()-i > nums2.size()-j)
            return findKth(nums2,j,nums1,i,k);
        if (nums1.size() == i)
            return nums2[j+k-1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        
        int lhs = min((i+k/2), (int)nums1.size());
        int rhs = j+k-lhs+i;
        if (nums1[lhs-1] < nums2[rhs-1])
            return findKth(nums1,lhs,nums2,j,k-lhs+i);
        else if (nums1[lhs-1] > nums2[rhs-1])
            return findKth(nums1,i,nums2,rhs,k-rhs+j);
        else
            return nums1[lhs-1];
    }
