class Solution
{
public:
    int trap(const vector<int>& A) 
    {
        if (A==null) return 0;
        std::stack<int> s;
        int i = 0, maxWater = 0, maxBotWater = 0;
        while (i < A.length)
        {
            if (s.isEmpty() || A[i]<=A[s.peek()])
            {
                s.push(i++);
            }
            else
            {
                int bottom = s.pop();
                maxBottomWater = s.isEmpty()?
                0
                :
                (Math.min(A[s.peek()],A[i])-A[bottom])*(i-s.peek()-1);
                maxWater += maxBotWater;
            }
        }
        return maxWater;
    }
}
/*
** water will be trapped when a valley (v shape) exists, a the total size can be added up level by level.
** we need a stack to keep track of the desending (left) side of the valley. 
*/
