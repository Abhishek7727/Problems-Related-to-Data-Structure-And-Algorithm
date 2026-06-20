class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& arr) {
        arr.push_back({1,0});
         sort(arr.begin(),arr.end());
        if(arr.back()[0]!=n)
        arr.push_back({n,n-1});
       
        int m=arr.size();
        for(int i=1;i<m;i++)
        {
            int dist=arr[i][0]-arr[i-1][0];
            arr[i][1]=min(arr[i][1],arr[i-1][1]+dist);
        }
        long long ans=0;
        for(int i=m-2;i>=0;i--)
        {
             int dist=arr[i+1][0]-arr[i][0];
             arr[i][1]=min(arr[i][1],arr[i+1][1]+dist);
        }
     //long long ans=0;
        for(int i=1;i<m;i++)
        {
            long long x1=arr[i-1][0];
            long long h1=arr[i-1][1];

            long long x2=arr[i][0];
            long long h2=arr[i][1];
            long long d=x2-x1;
            ans=max(ans,(h1+h2+d)/2);

        }
        return (int)ans;

        

        
    }
};