class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& arr,int i,int j,vector<vector<bool>>&vis)
    {
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int row=i+x[k];
            int col=j+y[k];
            if(row<0 || col<0 || row>=arr.size() || col>=arr[0].size())
            continue;
            if(vis[row][col])
            continue;
            if(arr[i][j]<=arr[row][col])
            dfs(arr,row,col,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        for(int j=0;j<m;j++)
        {
            dfs(arr,0,j,pacific);
        }
        for(int i=0;i<n;i++)
        {
            dfs(arr,i,0,pacific);
        }
        for(int i=0;i<n;i++)
        {
            dfs(arr,i,m-1,atlantic);
        }
        for(int j=0;j<m;j++)
        {
            dfs(arr,n-1,j,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;

        
    }
};