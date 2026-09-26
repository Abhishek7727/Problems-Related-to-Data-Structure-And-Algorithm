class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead;
        unordered_set<string>vis;
        queue<pair<string,int>>q;

        for(string str:deadends)
        {
            dead.insert(str);
        }
        if(dead.count("0000")==1)
        return -1;

        q.push({"0000",0});
        vis.insert("0000");

        while(!q.empty())
        {
            auto[state,dist]=q.front();
            q.pop();
            if(state==target)
            return dist;

           
            for(int i=0;i<4;i++)
            {
                 string next=state;
                next[i]=(next[i]-'0'+1)%10+'0';
                if(!dead.count(next) && !vis.count(next))
                {
                    q.push({next,dist+1});
                    vis.insert(next);
                }
                next=state;

                next[i]=(next[i]-'0'+9)%10+'0';
                 if(!dead.count(next) && !vis.count(next))
                {
                    q.push({next,dist+1});
                    vis.insert(next);
                }

            }

        }
        return -1;
    }
};