class Solution {
public:
    int solve(vector<vector<int>>& arr, int mid)
    {
        int n=arr.size();
        int m=arr[0].size();
        int row=n-1;
       int col=0;
        int count=0;
        while(row>=0 && col<m)
        {
            if(arr[row][col]>mid)
            row--;
            else
            {
                count+=(row+1);
                col++;

            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& arr, int k) {
        
        int n=arr.size();
        int m=arr[0].size();
        int low=arr[0][0];
        int high=arr[n-1][m-1];
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=solve(arr,mid);
            if(ans<k)
            {
              low=mid+1;
            }
            else
            {
                res=mid;
                high=mid-1;
                
            }
        }
        return res;
    }
};