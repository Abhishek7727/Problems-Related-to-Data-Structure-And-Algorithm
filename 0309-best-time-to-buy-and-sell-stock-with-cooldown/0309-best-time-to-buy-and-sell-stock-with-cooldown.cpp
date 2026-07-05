class Solution {
public:
     int solve(int index,int buy,
              vector<int>& price,
              vector<vector<int>>& dp)
    {
        if(index>=price.size())
            return 0;

        if(dp[index][buy]!=-1)
            return dp[index][buy];

        if(buy)
        {
            return dp[index][buy]=max(
                -price[index]+solve(index+1,0,price,dp),
                 solve(index+1,1,price,dp)
            );
        }

        return dp[index][buy]=max(
            price[index]+solve(index+2,1,price,dp),
            solve(index+1,0,price,dp)
        );
    }

    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<int>> dp(n,
                               vector<int>(2,-1));

        return solve(0,1,prices,dp);
    }
        
    
};