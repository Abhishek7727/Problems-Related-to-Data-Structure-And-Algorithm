class Solution {
public:

    typedef pair<int,pair<int,int>> pp;

    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return false;

        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0,0}});

        while(!pq.empty())
        {
            pp p = pq.top();
            pq.pop();

            int cost = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(cost > dist[row][col])
                continue;

            for(int k=0;k<4;k++)
            {
                int r = row + x[k];
                int c = col + y[k];

                if(!isValid(r,c,n,n))
                    continue;

                int newcost = max(cost, grid[r][c]);

                if(newcost < dist[r][c])
                {
                    dist[r][c] = newcost;

                    pq.push({newcost,{r,c}});
                }
            }
        }

        return dist[n-1][n-1];
    }
};