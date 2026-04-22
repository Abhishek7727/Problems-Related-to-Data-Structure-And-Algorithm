class Solution {
public:
    int comp(string &q, string & d)
    {
        int diff=0;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            if(d[i]!=q[i])
            diff++;
            if(diff>2)
            break;
        }
        return diff;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;

        for(int i=0;i<q.size();i++)
        {
            for(int j=0;j<d.size();j++)
            {
                int diff=comp(q[i],d[j]);
                if(diff<=2){
                ans.push_back(q[i]);
                break;
                }
            }
        }
        return ans;
    }
};