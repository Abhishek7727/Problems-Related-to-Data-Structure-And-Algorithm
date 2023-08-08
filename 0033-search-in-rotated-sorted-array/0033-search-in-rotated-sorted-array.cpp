class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ll=0;
        int hh=nums.size()-1;
        while(ll<=hh)
        {
            int mid=(ll+hh)>>1;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]>=nums[ll])
            {
                if(nums[ll]<=target && target<=nums[mid])
                hh=mid-1;
                else
                ll=mid+1;
            }
            else
            {
                if(nums[mid]<=target && target<=nums[hh])
                ll=mid+1;
                
                else 
                hh=mid-1;
                
            }
        }
        return -1;
        
    }
};