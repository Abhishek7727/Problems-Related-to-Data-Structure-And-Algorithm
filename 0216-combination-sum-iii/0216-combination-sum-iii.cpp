class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void solve(int start,int k,int target)
    {
        if(curr.size()==k && target==0)
        {
            ans.push_back(curr);
            return ;
        }
        else if(target<0 ||curr.size()>=k)
        {
             return ;
        }
        
        for(int num=start;num<=9;num++)
        {
            if(target-num<0)
            {
              continue;
            }
            curr.push_back(num);
            solve(num+1,k,target-num);
            curr.pop_back();
        }



    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1,k,n);
        return ans;
    }
};