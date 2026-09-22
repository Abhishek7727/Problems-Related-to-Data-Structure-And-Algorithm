class Solution {
public:
    bool dfs(int node,int target,vector<vector<int>>&adj,vector<bool>&vis)
    {
        if(node==target)
        return true;
        vis[node]=true;
        for(int nei:adj[node])
        {
            if(!vis[nei])
            {
                if(dfs(nei,target,adj,vis))
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        
        for(auto & x:edges)
        {
            int u=x[0];
            int v=x[1];
            vector<bool>vis(n+1,0);

            if(dfs(u,v,adj,vis))
            {
                return{u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};