class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    typedef pair<int,pair<int,int>> p;

    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();

        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;

        res[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            p node=pq.top(); pq.pop();
            int dist=node.first;
            int row=node.second.first;
            int col=node.second.second;

            if(dist>res[row][col])
            continue;

            for(int k=0;k<4;k++)
            {
                int r=row+x[k];
                int c=col+y[k];
                if(!isValid(r,c,n,m))
                continue;

                int diff=abs(arr[row][col]-arr[r][c]);
                int newWt=max(diff,dist);
                if(newWt<res[r][c])
                {
                    res[r][c]=newWt;
                    pq.push({newWt,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
        
    }
};