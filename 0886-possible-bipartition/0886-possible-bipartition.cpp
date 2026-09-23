class Solution {
public:
    bool res=true;
    void  dfs(int node,int c,vector<int>&color,vector<vector<int>>&adj)
    {
        color[node]=c;
        for(int i=0;i<adj[node].size();i++)
        {
            int neig=adj[node][i];
            if(color[neig]!=-1 && color[neig]==c)
            res=false;
            if(color[neig]==-1)
            dfs(neig,1-c,color,adj);
        }
        return ;
    }
    bool possibleBipartition(int n, vector<vector<int>>& arr) {
        vector<int>color(n,-1);
        vector<vector<int>>adj(n);
        for(int i=0;i<arr.size();i++)
        {
           int u=arr[i][0]-1;
           int v=arr[i][1]-1;
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            dfs(i,0,color,adj);
        }
        return res;
    }
};