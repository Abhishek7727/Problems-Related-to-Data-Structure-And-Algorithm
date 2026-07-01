class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDeg(numCourses,0);
        for(int i=0;i<arr.size();i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
            inDeg[arr[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDeg[i]==0)
            q.push(i);
        }
        int ans=0;
        while(!q.empty())
        {
            int node=q.front();q.pop();
            ans++;
            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i];
                inDeg[neigh]--;
                if(inDeg[neigh]==0)
                {
                    q.push(neigh);
                }
            }

        }
        return ans==numCourses;
    }
};