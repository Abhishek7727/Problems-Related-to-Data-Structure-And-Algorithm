class Solution {
public:

    bool check(int minEdge,
               vector<vector<int>>& edges,
               vector<bool>& online,
               long long k)
    {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);

        for(auto &e:edges)
        {
            if(e[2] < minEdge)
                continue;

            int u=e[0];
            int v=e[1];

            if(v!=n-1 && !online[v])
                continue;

            adj[u].push_back({v,e[2]});
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<long long> dp(n,1e18);

        dp[0]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto &it:adj[node])
            {
                int nbr=it.first;
                int wt=it.second;

                if(dp[node]!=1e18)
                {
                    dp[nbr]=min(dp[nbr],
                                dp[node]+wt);
                }

                indegree[nbr]--;

                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }

        return dp[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {
        int high=0;

        for(auto &e:edges)
            high=max(high,e[2]);

        int low=0;

        int ans=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(mid,edges,online,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return ans;
    }
};