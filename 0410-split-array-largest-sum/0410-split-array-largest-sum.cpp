class Solution {
public:
    bool solve(vector<int>&nums,int k,int mid)
    { 
        int currSum=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(currSum+nums[i]<=mid)
            {
                currSum+=nums[i];
            }
            else
            {
                count++;
                currSum=nums[i];
                if(count>k)
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};