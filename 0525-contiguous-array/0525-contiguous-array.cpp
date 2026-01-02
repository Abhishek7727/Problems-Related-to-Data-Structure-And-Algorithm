
  class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
       int res=0;
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           if(sum==0)
           {
               cnt=i+1;
           }
           if(mp.find(sum)==mp.end())
           {
               mp.insert({sum,i});
           }
           if(mp.find(sum)!=mp.end())
           {
               cnt=max(cnt,i-mp[sum]);
           }

       }
       return cnt;
        
    }

};