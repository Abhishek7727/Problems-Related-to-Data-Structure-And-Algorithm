class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int count=0;
        int j=0;
        for(int i=1;i<=nums[nums.size()-1];i++)
        {
            if(nums[j]==i)
            j++;
            else
            {
                count++;
                if(count==k)
                return i;
            }
        }
        return nums[nums.size()-1]+k-count;
    }
};