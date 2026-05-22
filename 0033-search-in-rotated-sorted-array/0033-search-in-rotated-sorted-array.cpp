class Solution {
public:
    int findFirst(vector<int>&nums)
    {
        int res=0;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[0]<=nums[mid])
            low=mid+1;
            else
            {
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
    int binarySearch(vector<int>&arr,int low,int high,int target)
    {
       /// int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target)
            return mid;
            else if(arr[mid]>target)
            {
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int firstEle=findFirst(nums);
       if(firstEle == 0)
{
    return binarySearch(nums,0,n-1,target);
}

       if(target>=nums[0] && target<=nums[firstEle-1])
       {
        return binarySearch(nums,0,firstEle-1,target);
       }
       else
       return binarySearch(nums,firstEle,n-1,target);
        
    }
};