class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isValid(int r,int c,int n,int m)
    {
        if(r>=n||c>=m ||r<0 ||c<0)
        return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){
                dist[i][j]=0;
                q.push({i,j});
                }

            }
        }
        while(!q.empty())
        {
               auto p=q.front();q.pop();
                int row=p.first;
                int col=p.second;
                for(int k=0;k<4;k++)
                {
                    int r=row+dx[k];
                    int c=col+dy[k];
                    if(isValid(r,c,n,m) && dist[r][c]==-1 )
                    {
                        dist[r][c]=dist[row][col]+1;
                        q.push({r,c});
                        
                    }
                }
        }
        return dist;
    }
};