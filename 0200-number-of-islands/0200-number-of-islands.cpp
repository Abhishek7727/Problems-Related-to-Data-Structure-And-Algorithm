class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 ||j<0 ||i>=n ||j>=m)
        return false;
        return true;
    }
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    void bfs(vector<vector<char>>&arr,int i,int j,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            auto p=q.front(); q.pop();
            int row=p.first;
            int col=p.second;
            for(int k=0;k<4;k++)
            {
                int r=row+x[k];
                int c=col+y[k];
                if(isValid(r,c,n,m) && arr[r][c]=='1')
                {
                    arr[r][c]='0';
                    q.push({r,c});
                }
            }
            
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int isLand=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,n,m);
                    isLand++;
                }
            }
        }
        return isLand;
    }
};