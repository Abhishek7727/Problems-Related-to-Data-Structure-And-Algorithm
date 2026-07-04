class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<roads.size();i++)
        {
             adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
              adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        vector<bool>vis(n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto p:adj[node])
            {
                ans=min(ans,p.second);
                if(!vis[p.first])
                {
                    vis[p.first]=1;
                    q.push(p.first);
                }
            }
        }
        return ans;
    }
};