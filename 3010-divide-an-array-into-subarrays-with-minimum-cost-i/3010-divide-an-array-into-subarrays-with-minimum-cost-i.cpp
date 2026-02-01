class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        int firstMin=100;
        int secondMin=100;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=firstMin)
            {
                secondMin=firstMin;
                firstMin=nums[i];


            }
            else if(nums[i]<secondMin)
            {
                secondMin=nums[i];
            }
        }
        return sum+firstMin+secondMin;
        
        
    }
};