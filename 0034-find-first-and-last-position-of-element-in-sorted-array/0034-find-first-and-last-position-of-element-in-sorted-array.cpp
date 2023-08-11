class Solution {
public:
    int solve(vector<int>nums,int target,int find)
    {
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target<nums[mid])
            end=mid-1;
            else if(target>nums[mid])
            start=mid+1;
            else{
                ans=mid;
                if(find==0)
                end=mid-1;
                else
                start=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {solve(nums,target,0),solve(nums,target,1)};
        
    }
};