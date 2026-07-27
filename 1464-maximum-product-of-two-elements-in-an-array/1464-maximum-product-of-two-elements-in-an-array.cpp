class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=nums[0];
        int second=0;
      for(int i=1;i<nums.size();i++)
        {
            int x=nums[i];
            if(x>first)
            {
                second=first;
                first=x;
            }
            else
            {
                if(x>second)
                second=x;
            }
        }
        return (first-1)*(second-1);
        
    }
};