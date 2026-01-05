class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res=0;
        int maxEnd=nums[0],minEnd=nums[0];
        int maxSum=nums[0], minSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
           maxEnd=max(maxEnd+nums[i],nums[i]);
           maxSum=max(maxSum,maxEnd);
        
           minEnd=min(minEnd+nums[i],nums[i]);
           minSum=min(minSum,minEnd);
          
            
        }
        return max(maxSum,abs(minSum));
    }
};