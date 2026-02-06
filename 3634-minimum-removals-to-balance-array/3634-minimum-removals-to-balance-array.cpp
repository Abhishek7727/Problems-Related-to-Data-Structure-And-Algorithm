class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       int count = INT_MIN;
       int j = 0;
   
       for(int i=0;i<n;i++)
       {
       while((long long) nums[i] > (long long) nums[j]*k)
        {
           j++;
        }
        count=max(count, i - j + 1);

       }

       return n-count;
       }


};