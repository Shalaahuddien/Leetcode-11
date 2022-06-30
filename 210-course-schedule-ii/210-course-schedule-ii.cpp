class Solution {
public:
    // bfs
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i]) indegree[it]++;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push(i);
        vector<int> res(n);
        int i=0;
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            res[i++]=cur;
            for(auto it:adj[cur])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(i==n) return res;
        return {};
    }
};