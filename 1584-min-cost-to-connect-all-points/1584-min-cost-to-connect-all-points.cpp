class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minCost(n, INT_MAX);
        vector<bool> visited(n, false);

        minCost[0] = 0;

        int ans = 0;

        for(int count = 0; count < n; count++) {

            // Find minimum cost unvisited node
            int node = -1;

            for(int i = 0; i < n; i++) {

                if(!visited[i] &&
                   (node == -1 || minCost[i] < minCost[node])) {

                    node = i;
                }
            }

            // Add node to MST
            visited[node] = true;
            ans += minCost[node];

            // Update costs of remaining nodes
            for(int i = 0; i < n; i++) {

                if(!visited[i]) {

                    int cost =
                        abs(points[node][0] - points[i][0]) +
                        abs(points[node][1] - points[i][1]);

                    minCost[i] = min(minCost[i], cost);
                }
            }
        }

        return ans;
    }
};