class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
          int n = s.size();

        queue<int> q;

        vector<int> vis(n,0);

        q.push(0);

        vis[0] = 1;

        int farthest = 0;

        while(!q.empty())
        {
            int idx = q.front();
            q.pop();

            // reached end
            if(idx == n - 1)
                return true;

            // new range to explore
            int start = max(idx + minJump, farthest + 1);

            int end = min(idx + maxJump, n - 1);

            for(int j = start; j <= end; j++)
            {
                if(s[j] == '0' && !vis[j])
                {
                    vis[j] = 1;

                    q.push(j);
                }
            }

            // mark explored
            farthest = end;
        }

        return false;
    }
};