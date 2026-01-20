class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        int row=n-1,col=0;
        while(row>=0 && col<m)
        {
            if(arr[row][col]==target)
            {
                return true;
            }
            else if(arr[row][col]>target)
            {
                row--;
            }
            else
            col++;
        }
        return false;
        
    }
};