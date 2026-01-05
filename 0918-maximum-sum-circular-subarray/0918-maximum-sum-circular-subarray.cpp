class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_sum=nums[0];
        int resmax=nums[0];
        int max_sum=nums[0],min_sum=nums[0];
        int resmin=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            max_sum=max(nums[i],max_sum+nums[i]);
            resmax=max(resmax,max_sum);

            min_sum=min(nums[i],min_sum+nums[i]);
            resmin=min(resmin,min_sum);

        }
        return resmax>0 ? max(resmax,curr_sum-resmin) :resmax;

    }
};