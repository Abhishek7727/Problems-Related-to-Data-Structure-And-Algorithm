class Solution {
public:
    void dfs(int start,vector<int>adj[],vector<int>&visit)
    {
        visit[start]=1;
        for(auto it:adj[start])
        {
            if(!visit[it])
                dfs(it,adj,visit);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visit(n,0);
         vector<int>adj[n]; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&& i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                cnt++;
                dfs(i,adj,visit);
            }
        }
        return cnt;
    }
};