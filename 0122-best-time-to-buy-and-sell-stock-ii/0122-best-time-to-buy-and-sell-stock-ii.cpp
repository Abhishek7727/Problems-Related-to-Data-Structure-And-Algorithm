class Solution {
public:
    int solve(int ind,int buy,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind==arr.size())
        return 0;

        if(dp[ind][buy]!=-1)
        return dp[ind][buy];

        if(buy)
        {
            int take=-arr[ind]+solve(ind+1,0,arr,dp);

            int skip=solve(ind+1,1,arr,dp);

            return dp[ind][buy]=max(take,skip);
        }
        else
        {
            int sell=arr[ind]+solve(ind+1,1,arr,dp);
            int skip=solve(ind+1,0,arr,dp);
            return dp[ind][buy]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};