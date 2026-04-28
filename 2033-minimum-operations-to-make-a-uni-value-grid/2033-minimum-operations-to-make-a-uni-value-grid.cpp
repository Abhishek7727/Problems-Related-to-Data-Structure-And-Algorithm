class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    
   vector<int>arr;
   for(int i=0;i<grid.size();i++)
   {
    for(int j=0;j<grid[0].size();j++)
    {
        arr.push_back(grid[i][j]);
    }
   }
   sort(arr.begin(),arr.end());
   int n=arr.size();
   int mid=n/2;
   int ans=0;
   int rem=arr[0]%x;
   for(int i=0;i<n;i++)
   {
    if(arr[i]%x!=rem)
    return -1;
    int step=abs(arr[i]-arr[mid]);
    ans+=step/x;
   }
   return ans;


        
    }
};