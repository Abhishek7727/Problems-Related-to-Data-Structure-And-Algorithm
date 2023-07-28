class Solution {
public:
   int score(vector<int>& nums,int start,int end)
   {
       if(start==end)return nums[end];
       int choosestart=nums[start]-score(nums,start+1,end);
       int chooseend=nums[end]-score(nums,start,end-1);
       return max(choosestart,chooseend);
   }
    bool PredictTheWinner(vector<int>& nums) {
        int s=0;
        int end=nums.size()-1;
        return score(nums,s,end)>=0;
        
    }
};