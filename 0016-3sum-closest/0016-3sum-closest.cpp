class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int close_sum= INT_MAX/2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
                int curr_sum=nums[i]+nums[left]+nums[right];
                if(abs(curr_sum-target)<abs(close_sum-target))
                {
                    close_sum=curr_sum;
                }
                if(curr_sum<target)
                {
                    left++;
                }
                else if(curr_sum>target)
                {
                     right--;
                }
                else
                {
                    return curr_sum;
                }
            }
        }
        return close_sum;
    }
};