class Solution {
public:
    int solve(int ind,int buy,vector<int>&arr,int fee,vector<vector<int>>&dp)
    {
        if(ind==arr.size())
        return 0;

        if(dp[ind][buy]!=-1)
        return dp[ind][buy];

        if(buy)
        {
            return dp[ind][buy]=max(-arr[ind]+solve(ind+1,0,arr,fee,dp),solve(ind+1,1,arr,fee,dp));
        }
        else
        return dp[ind][buy]=max(arr[ind]-fee+solve(ind+1,1,arr,fee,dp),solve(ind+1,0,arr,fee,dp));
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return solve(0,1,arr,fee,dp);
        
    }
};