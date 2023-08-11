class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==k)
                return true;
            if(nums[mid]==nums[start]&&nums[mid]==nums[end])
            {
                start++;
                end--;
                continue;
            }
            if(nums[start]<=nums[mid])
            {
                if(nums[start]<=k && nums[mid]>=k)
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
            else
            {
                if(nums[mid]<=k && nums[end]>=k)
                {
                    start=mid+1;
                }
                else
                    end=mid-1;
            }
        }
        return false;
    }
};