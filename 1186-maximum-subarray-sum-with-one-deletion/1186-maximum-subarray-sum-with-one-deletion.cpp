class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int power=0;
        int nopower=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            // no power use yet
            int v1=nums[i];
            int v2=nopower+nums[i];

            int v3=power+nums[i];

            int v4 =nopower;

            int maxsum=max(max(v1,v2),max(v3,v4));
            res=max(res,maxsum);
            nopower=max(v1,v2);
            power= max(v3,v4);

        }
        return res;
    }
};