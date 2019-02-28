    int longestValidParentheses(string s) 
    {
        int size = s.size();
        int res = 0;
        
        vector<int> dp(size+1, 0);
        for (int i = 1; i < size; ++i)
        {
            if (s[i] == ')')
            {
                int left = i - dp[i] - 1;
                if (left>=0 && s[left]=='(')
                    dp[i+1] = dp[i]+2+dp[left];
                res = max(res, dp[i+1]);
            }
        }
        return res;
    }
