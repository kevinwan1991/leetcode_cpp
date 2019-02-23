typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> g[n + 1];
        for (const auto& t : times) 
        {
            g[t[0]].push_back(make_pair(t[1], t[2]));
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(make_pair(0, k));
        int u, v, w;
		    
        vector<bool> vis(n + 1, false);
        while (!pq.empty()) 
        {
            pii p = pq.top(); pq.pop();
            u = p.second;
			      if (vis[u]) continue; // longer path in priority queue for the same node will be disgarded.
            for (auto& to : g[u]) 
            {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) 
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
			      vis[u] = true;
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
};
