class SegmentTree
{
public:
    SegmentTree(vector<int> nums)
    {
        int size = nums.size();
        tree.resize(size*2);
        
        for (int i = size; i < 2*size; ++i)
            tree[i] = nums[i-size];
        
        for (int i = size-1; i > 0; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    void update(int i, int val) 
    {
        int pos = i + tree.size()/2;
        int off = val - tree[pos];
        while (pos)
        {
            tree[pos] += off;
            pos /= 2;
        }
    }
    
    int sumRange(int i, int j) 
    {
        int n = tree.size()/2;
        i += n;
        j += n;
        
        int sum = 0;
        while (i <= j)
        {
            if (i%2 == 1)
                sum += tree[i];
            if (j%2 == 0)
                sum += tree[j];
            i = (i+1)/2;
            j = (j-1)/2;
        }
        return sum;
    }
private:
    vector<int> tree;
};
