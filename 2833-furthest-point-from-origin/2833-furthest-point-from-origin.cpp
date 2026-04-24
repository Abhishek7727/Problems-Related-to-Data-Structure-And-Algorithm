class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,s=0;
        int n=moves.length();
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='L')
            l++;
            else if(moves[i]=='R')
            r++;
            else
            s++;
        }
        return abs(l-r)+s;
        
    }
};