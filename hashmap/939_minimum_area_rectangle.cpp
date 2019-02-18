class Solution {
public:
int getHash(int x, int y) 
{
    return (x << 16) + y;
}
    
int minAreaRect(vector<vector<int>>& points) 
{
    unordered_set<int> st;
    for (auto &p: points) st.insert(getHash(p[0], p[1]));
    int ans = INT_MAX;
    for (int i = 0; i < points.size(); i++) 
    {
        vector<int> &p1 = points[i];
        for (int j = i+1; j < points.size(); j++) //pair(p1,p2) == pair(p2,p1), so j = i+1;
        {
            vector<int> &p2 = points[j];
            if (p1[0] != p2[0] && p1[1] != p2[1] 
                && st.count(getHash(p1[0], p2[1])) 
                && st.count(getHash(p2[0], p1[1]))) 
            {
                int area = abs(p1[0]-p2[0]) * abs(p1[1]-p2[1]);
                ans = min(ans, area);
            }
        }
    }
    return ans < INT_MAX ? ans : 0;
}
}
