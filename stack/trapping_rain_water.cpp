class Solution
{
public: int trap(const vector<int>& A) {
        if (A==null) return 0;
        std::stack<int> s;
        int i = 0, maxWater = 0, maxBotWater = 0;
        while (i < A.length){
            if (s.isEmpty() || A[i]<=A[s.peek()]){
                s.push(i++);
            }
            else {
                int bottom = s.pop();
                maxBottomWater = s.isEmpty()? // empty means no il
                0:(Math.min(A[s.peek()],A[i])-A[bottom])*(i-s.peek()-1);
                maxWater += maxBotWater;
            }
        }
        return maxWater;
    }
}
