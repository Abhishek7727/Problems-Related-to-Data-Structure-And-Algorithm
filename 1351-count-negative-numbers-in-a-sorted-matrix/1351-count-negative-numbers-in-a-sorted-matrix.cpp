class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m= grid[0].size();
        for(int i=0;i<n;i++)
        {
            // if(grid[m-1][0]>=0)
            // continue;
             for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]<0)
                count++;
            }
        }
        return count;
        
    }
};