class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size()==1)
        return abs(nums[0]);
        int minSum=nums[0];
        int maxSum=nums[0];
        int ans=nums[0];
        int currMin=nums[0];
        int currMax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            currMax=max(currMax+nums[i],nums[i]);
            currMin=min(currMin+nums[i],nums[i]);
            ans=max(ans,max(abs(currMin),currMax));
        }
        return ans;
        
    }
};