class Solution {
public:
    int solve(int ind,int buy,int limit,vector<int>&arr,vector<vector<vector<int>>>&dp)
    {
        if(ind==arr.size())
        return 0;

        if(limit==0)
        return 0;
        
        if(dp[ind][buy][limit]!=-1)
        {
            return dp[ind][buy][limit];
        }

        if(buy)
        {
            dp[ind][buy][limit]=max(-arr[ind]+solve(ind+1,0,limit,arr,dp),solve(ind+1,1,limit,arr,dp));
        }
        else
        {
            dp[ind][buy][limit]=max(arr[ind]+solve(ind+1,1,limit-1,arr,dp),solve(ind+1,0,limit,arr,dp));
        }
        return dp[ind][buy][limit];
    }
    int maxProfit(vector<int>& price) {
        int n=price.size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,price,dp);

    }
};