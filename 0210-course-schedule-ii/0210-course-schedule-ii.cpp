class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build Graph
        for(auto &it : prerequisites){

            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){

            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int nbr : adj[node]){

                indegree[nbr]--;

                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(topo.size() != numCourses)
            return {};

        return topo;
    }
};