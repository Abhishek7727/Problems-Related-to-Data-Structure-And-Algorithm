class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {


        int zerocount=0;
        int ans=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<n)
        {
           if(nums[j]==0)
            {
            //    ans= max(j-i+1,ans);
                zerocount++;
            

            }


            
                while( zerocount>k)
                {
                   if(nums[i]==0)
                   zerocount--;

                   i++;


                }
            

            
            ans= max(j-i+1,ans);
            j++;

        }
        return ans;
        
    }
};