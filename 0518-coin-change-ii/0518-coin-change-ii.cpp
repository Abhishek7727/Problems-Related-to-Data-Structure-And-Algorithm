class Solution {
public:
   

    int change(int a, vector<int>& coins) {
         int n=coins.size();
        int dp[n+1][a+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=a;j++)
            {
                if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=1;
    
            }
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a;j++)
            {
                if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else if(coins[i-1]>j)
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][a];
        
    }
};