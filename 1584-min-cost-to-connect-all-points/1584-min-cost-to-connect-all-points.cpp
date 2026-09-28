class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,cost});
                adj[j].push_back({i,cost});


            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=0;
        vector<bool>vis(n,false);
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto[wt,node]=pq.top();
            pq.pop();
            if(vis[node])
            continue;

            vis[node]=true;
            ans+=wt;
            for(auto[nei,w]:adj[node])
            {
                if(!vis[nei])
                {
                    pq.push({w,nei});
                }
            }
        }
        return ans;
    }
};