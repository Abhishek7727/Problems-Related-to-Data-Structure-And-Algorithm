//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(int i , int j , vector<vector<char>>& grid , vector<vector<bool>> &visited)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        int rows=grid.size();
        int column=grid[0].size();
        
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            
            if(x+1<rows && y+1<column && visited[x+1][y+1]==false && grid[x+1][y+1]=='1')
            {
                visited[x+1][y+1]=true;
                q.push({x+1 , y+1});
            }
            if( y+1<column && visited[x][y+1]==false && grid[x][y+1]=='1')
            {
                visited[x][y+1]=true;
                q.push({x , y+1});
            }
            if(x+1<rows && visited[x+1][y]==false && grid[x+1][y]=='1')
            {
                visited[x+1][y]=true;
                q.push({x+1 , y});
            }
            if(x-1>=0 && y-1>=0 && visited[x-1][y-1]==false && grid[x-1][y-1]=='1')
            {
                visited[x-1][y-1]=true;
                q.push({x-1 , y-1});
            }
            if( y-1>=0 && visited[x][y-1]==false && grid[x][y-1]=='1')
            {
                visited[x][y-1]=true;
                q.push({x , y-1});
            }
            if(x-1>=0 && visited[x-1][y]==false && grid[x-1][y]=='1')
            {
                visited[x-1][y]=true;
                q.push({x-1 , y});
            }
            if(x-1>=0 && y+1 < column && visited[x-1][y+1]==false && grid[x-1][y+1]=='1')
            {
                visited[x-1][y+1]=true;
                q.push({x-1 , y+1});
            }
            if(x+1<rows && y-1 >=0 && visited[x+1][y-1]==false && grid[x+1][y-1]=='1')
            {
                visited[x+1][y-1]=true;
                q.push({x+1 , y-1});
            }
            
        }
    }  
       
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int cnt=0;

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(visited[i][j]==0 && grid[i][j]=='1')
               {
                   bfs(i,j,grid,visited);
                   cnt++;
               }
               
           }
       }
       return cnt;
       
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends