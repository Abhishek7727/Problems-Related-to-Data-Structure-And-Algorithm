
  class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int one=0,zero=0,res=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            zero++;
            else
            one++;

            int diff=zero-one;

            if(diff==0){
            res=i+1;
            continue;
            }

            else if(mp.find(diff)==mp.end())
            {
                mp[diff]=i;
            }
            else
            {
                res=max(res,i-mp[diff]);
            }

        
        }
        return res;
        
    }

};