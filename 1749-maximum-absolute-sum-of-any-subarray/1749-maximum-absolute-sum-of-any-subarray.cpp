class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res=0;
        int maxEnd=nums[0],minEnd=nums[0];
        int maxSum=nums[0], minSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            //Kadens se Maximum sum subarray nikalo Aur 
           maxEnd=max(maxEnd+nums[i],nums[i]);
           maxSum=max(maxSum,maxEnd);
         
         // Minimum sum subarray nikalna hai 
           minEnd=min(minEnd+nums[i],nums[i]);
           minSum=min(minSum,minEnd);
          
            
        }
        //Aur phir dono ka maximum nikal lo
        return max(maxSum,abs(minSum));
    }
};