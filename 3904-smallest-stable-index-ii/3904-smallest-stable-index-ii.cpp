class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=max(pre[i-1],nums[i]);
            suff[n-i-1]=min(suff[n-i],nums[n-i-1]);
        }

        for(int i=0;i<n;i++)
        {
            int temp=pre[i]-suff[i];
            if(temp<=k)
            {
                return i;
            }
        }
        return -1;
    }
};