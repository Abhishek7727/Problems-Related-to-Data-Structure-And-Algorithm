class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            int buy=-arr[i]+dp[i+1][0];
            int skip=dp[i+1][1];
            dp[i][1]=max(buy,skip);

            int sell=arr[i]+dp[i+1][1];

            int hold=dp[i+1][0];

            dp[i][0]=max(sell,hold);

        }
        return dp[0][1];
    }
};