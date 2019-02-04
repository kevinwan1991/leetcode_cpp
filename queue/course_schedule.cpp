    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pair : prerequisites)
        {
            graph[pair.first].insert(pair.second);
            ++indegree[pair.second];
        }
        
        queue<int> queue;
        for (int i = 0; i < numCourses; ++i)
            if (!indegree[i])
                queue.push(i);
        
        int counter = 0;
        while (!queue.empty())
        {
            int root = queue.front();
            queue.pop();
            ++counter;
            for (auto child : graph[root])
            {
                if (--indegree[child] == 0)
                    queue.push(child);
            }
        }
        return counter == numCourses;
    }
