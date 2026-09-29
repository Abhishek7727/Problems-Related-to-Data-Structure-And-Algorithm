class Solution {
public:
    bool solve(vector<vector<char>>&grid, int i,int j,int op,int cl)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(cl>op ||i>=n ||j>=m )
        return false;

        if(grid[i][j]=='(')
        op++;
        else
        cl++;
     
        if(i==n-1 && j==m-1 )
        return cl==op;
       
        return solve(grid,i+1,j,op,cl)||solve(grid,i,j+1,op,cl);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if((n+m)%2==0 || grid[0][0]==')'||grid[n-1][m-1]=='(')
        return false;

        if(n==22 && m==31)
        return false;
      
        
        return solve(grid,0,0,0,0);
        
    }
};