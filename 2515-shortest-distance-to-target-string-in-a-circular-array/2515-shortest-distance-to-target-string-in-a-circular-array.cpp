class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int step=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[(startIndex+step)%n]==target||words[(startIndex-step+n)%n]==target)
            {
                return step;
            }
            step++;
        }
        return -1;
        
    }
};