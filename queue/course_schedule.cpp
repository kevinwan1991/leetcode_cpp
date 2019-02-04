    // BFS
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


    // DFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++ i)
            if(!flag[i])
                if(DFS(matrix, visited, i, flag))
                    return false;
        return true;
    }
    bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
    {
        flag[b] = true;
        visited.insert(b);
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
            if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
                return true;
        visited.erase(b);
        return false;
    }
