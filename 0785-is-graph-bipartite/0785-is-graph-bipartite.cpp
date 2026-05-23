class Solution {
public:
    bool res=true;
    void bfs(vector<vector<int>>&adj,int node,int c,vector<int>& color)
    {
        queue<int>q;
        q.push(node);
        color[node]=c;
        while(!q.empty())
        {
            int temp=q.front(); q.pop();

            for(int i=0;i<adj[temp].size();i++)
            {
                int neigh=adj[temp][i];
                if(color[neigh]!=-1 && color[neigh]==color[temp]){
                res=false;
                return ;
                }
                else if(color[neigh]==-1)
                {
                    q.push(neigh);
                    color[neigh]=1-color[temp];
                }
            }
        }
        return ;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            bfs(adj,i,0,color);
        }
        return res;
    }
};