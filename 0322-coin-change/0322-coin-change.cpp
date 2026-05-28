class Solution {
public:
 int dp[15][10005];
    int solve(int idx,vector<int>&arr,int amt)
    {
        if(idx==0)
        {
            if(amt%arr[idx]==0)
            return amt/arr[idx];
            else 
            return 1e8;
        }
        //int notake =0+solve(idx-1,arr,amt)
        if(dp[idx][amt]!=-1)
        return dp[idx][amt];
        int take =solve(idx-1,arr,amt);
        int notTake=1e8;

        if(arr[idx]<=amt)
        {
            notTake= 1+solve(idx,arr,amt-arr[idx]);
        }
        return dp[idx][amt]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

       // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
      
        memset(dp, -1, sizeof(dp));
        int ans=solve(coins.size()-1,coins,amount);
        if(ans>=1e8)
        return -1;
        return ans;
        
    }
};