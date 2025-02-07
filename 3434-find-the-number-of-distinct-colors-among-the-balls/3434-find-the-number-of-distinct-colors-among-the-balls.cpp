class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        //vector<int>ans;
        unordered_map<int,int>ball,color;
        vector<int>ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            int b=q[i][0];
            int c=q[i][1];
            if(ball.find(b)!=ball.end())
            {
                int exitcol=ball[b];
                if(color[exitcol]==1)
                color.erase(exitcol);
                else
                color[exitcol]--;

                ball[b]=c;
                color[c]++;

            }
            else
            {
                ball[b]=c;
                color[c]++;
            }
            ans[i]=color.size();
        }
        return ans;

    }
};