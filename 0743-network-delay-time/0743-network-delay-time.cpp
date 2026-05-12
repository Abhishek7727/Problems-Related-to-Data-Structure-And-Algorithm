class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++)
        {
            int s=times[i][0];
            int d=times[i][1];
            int w=times[i][2];
            adj[s-1].push_back({d-1,w});
        }
        k--;
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty())
        {
            pair<int,int>p=pq.top();pq.pop();
        
           int d=p.first;
           int node=p.second;

           if(d>dist[node])
           continue;

           for(int i=0;i<adj[node].size();i++)
           {
            int neigh=adj[node][i].first;
            int wt=adj[node][i].second;
            if(d+wt<dist[neigh])
            {
                dist[neigh]=d+wt;
                pq.push({d+wt,neigh});
            }
           }
        }
        int res=-1;
        for(int i=0;i<n;i++)
        {
            res=max(res,dist[i]);
        }

      if(res==INT_MAX)
      return -1;
      return res;        

    }
};