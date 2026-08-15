class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool hasNoneZero=false;
        for(int x:nums)
        {
            xr=xr^x;
            if(xr!=0)
            {
                hasNoneZero=true;
            }
        }
        if(xr!=0)
        return nums.size();

        if(hasNoneZero)
        {
            return nums.size()-1;
        }
       return 0;
        
    }
};