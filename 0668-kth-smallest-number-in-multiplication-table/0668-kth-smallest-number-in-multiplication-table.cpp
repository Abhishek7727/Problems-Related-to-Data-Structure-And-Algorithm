class Solution {
public:
    int findValid(int row,int col,int mid)
    {
        long long i=row,j=1;
        int count=0;
        while(i>=1 && j<=col)
        {
            if(i*j<=mid)
            {
                count+=i;
                j++;
            }
            else
            {
                i--;
            }
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=n*m;
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            int ans=findValid(m,n,mid);
            if(ans>=k)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
        
    }
};