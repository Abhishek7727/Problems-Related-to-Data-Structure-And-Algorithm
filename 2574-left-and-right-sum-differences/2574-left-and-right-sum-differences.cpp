class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
         if(n==1)
         return {0};
        int currSum=0;
       int leftSum=0;
      int rightSum=0;
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            leftSum=currSum-nums[i];
            rightSum=totalSum-currSum;
            ans[i]=abs(leftSum-rightSum);
        }
        return ans;
       
    }
};