class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<mat.size();i++)
        {
            int sum=0;
            for(int j=0;j<mat[i].size();j++)
            {
                sum+=mat[i][j];
            }
            maxH.push({sum,i});
            if(maxH.size()>k)
            maxH.pop();
        }
        while(maxH.size()>0)
        {
            ans.push_back(maxH.top().second);
            maxH.pop();

        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};