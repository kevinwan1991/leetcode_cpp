public class BinaryIndexTree
{
    vector<int> bit;
    vector<int> arr;
    int n;
    
    public BinaryIndexTree(int[] nums) 
    {
        n = nums.length;
        arr = nums;
        bit = vector<int>(n + 1);
        for (int i = 0; i < n; i++) updateBIT(i + 1, arr[i]);
    }

    void update(int i, int val) 
    {
        int diff = val - arr[i];
        arr[i] = val;
        updateBIT(i + 1, diff);
    }
    
    void updateBIT(int j, int diff) 
    { 
        while (j <= n) 
        {
            bit[j] += diff;
            j += j & -j;
        }
    }

    public int sumRange(int i, int j) 
    {
        return getSum(j + 1) - getSum(i);
    }
    
    int getSum(int j) 
    {
        int sum = 0;
        while (j > 0) 
        {
            sum += bit[j];
            j -= j & -j;
        }
        return sum;
    }
}
