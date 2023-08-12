class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        if(nums.size()==0)
            return true;
        int n=numCourses;
        int m=nums[0].size();
        vector<int>adj[n];
        for(auto it:nums)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return (n==topo.size());
        
    }
};