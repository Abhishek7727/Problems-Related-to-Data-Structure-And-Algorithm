class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        if(servers.size()==1)
        {

            vector<int>res(tasks.size(),0);
            return res;
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> available, notavailable;
        for(int i=0;i<servers.size();i++)
        {
            available.push({servers[i],i});
        }
        vector<int> ans(tasks.size());
        int time = 0;
        for(int i=0;i<tasks.size();i++)
        {
            time = max(time,i);
            if(available.empty() && notavailable.top().first > time)
            {
                time = notavailable.top().first;
            }
            while(!notavailable.empty() && notavailable.top().first <= time)
            {
                int idx = notavailable.top().second;
                available.push({servers[idx],idx});
                notavailable.pop();
            }
            if(!available.empty())
            {
                int idx = available.top().second;
                ans[i] = idx;
                available.pop();
                notavailable.push({time+tasks[i], idx});
            }
        }
        return ans;
    }
};