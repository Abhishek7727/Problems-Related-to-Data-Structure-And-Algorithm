class Solution {
public:
    bool isPossible(vector<int>&nums,int mid,int op)
    {
        int count=0;
        for(int x:nums)
        {
            
            
                count+=(x-1)/mid;
                
                if(count>op)
                return false;
            
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOp) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(isPossible(nums,mid,maxOp))
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