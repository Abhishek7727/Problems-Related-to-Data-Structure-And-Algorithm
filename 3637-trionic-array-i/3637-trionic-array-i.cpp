class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0]>=nums[1])
        return false;
        if(nums[nums.size()-1]<=nums[nums.size()-2])
         return false;

        int cnt=0;
        for(int i=1;i<nums.size()-1;i++)
        { 
            if(nums[i]==nums[i-1])
            return false;
            if(nums[i]>nums[i+1]&& nums[i]>nums[i-1])
            cnt++;
            else if(nums[i]<nums[i+1]&& nums[i]<nums[i-1])
            cnt++;

          
        }
        if(cnt==2)
        return true;
        else
        return false;

    }
};