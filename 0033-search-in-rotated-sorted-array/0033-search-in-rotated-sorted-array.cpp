class Solution {
public:
    int solve(vector<int>& nums)
    {
        int res=0;
        int n=nums.size();

        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[n-1])
            {
                low=mid+1;
            }
            else
            {
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
    int binarySearch(vector<int>& nums,int k,int low,int high)
    {
         int res=-1;
         int start=low,end=high;
         while(start<=end)
         {
            int mid=(start+end)/2;
            if(nums[mid]==k)
            return mid;
            else if(nums[mid]>k)
            {
                end=mid-1;
            }
            else{
                start=mid+1;
            }
         }
         return  res;

    }
    int search(vector<int>& nums, int target) {
        int firstElement=solve(nums);
        int a=binarySearch(nums,target,0,firstElement-1);
        int b=binarySearch(nums,target,firstElement,nums.size()-1);
        if(a==-1)
        return b;
        else
        return a;

        
    }
};