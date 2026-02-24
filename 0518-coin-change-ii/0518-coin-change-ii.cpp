class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<long>>dp(coins.size(),vector<long>(amount+1,-1));
        return solve(coins,coins.size()-1,amount,dp);
    }
    int solve(vector<int>&arr,int ind,int amt,vector<vector<long>>&dp)
    {
        if(ind==0)
        {
        return (amt%arr[0]==0?1:0);
        }
          if (dp[ind][amt] != -1)
        return dp[ind][amt];

        if(arr[ind]<=amt)
        {
            return dp[ind][amt]=solve(arr,ind,amt-arr[ind],dp)+solve(arr,ind-1,amt,dp);
        }
        else
        return dp[ind][amt]=solve(arr,ind-1,amt,dp);
    }
};