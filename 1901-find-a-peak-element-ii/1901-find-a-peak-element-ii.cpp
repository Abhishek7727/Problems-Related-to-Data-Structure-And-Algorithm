class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int maxCal=0;
            for(int i=1;i<m;i++)
            {
                if(mat[mid][i]>mat[mid][maxCal])
                maxCal=i;
            }

            int curr=mat[mid][maxCal];
            
            int up=(mid>0)?mat[mid-1][maxCal]:-1;
            int down=(mid<n-1)?mat[mid+1][maxCal]:-1;

            if(curr>up && curr>down)
            {
                return {mid,maxCal};
            }
            if(down>curr)
            {
                low=mid+1;
            }
            else
            high=mid-1;

        }
        return {-1,-1};
    }
};