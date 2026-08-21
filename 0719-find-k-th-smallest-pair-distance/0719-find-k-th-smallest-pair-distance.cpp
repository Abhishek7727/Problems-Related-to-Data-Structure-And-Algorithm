class Solution {
public:
    bool canPair(vector<int>nums,int k,int mid)
    {
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            while(j<nums.size() && nums[j]-nums[i]<=mid)
            j++;
            count+=j-i-1;
            if(count>=k)
            return true;

        }
        return false;
    }
    int smallestDistancePair(vector<int>& coins, int k) {
         sort(coins.begin(),coins.end());
       int low=0;
       int high=coins.back()-coins.front();
       int ans=-1;
       while(low<=high)
       {
            int mid=low+(high-low)/2;

            if(canPair(coins,k,mid))
            {
                ans=mid;
                high=mid-1;

            }
            else
            low=mid+1;
       }
        return low;
    }
};