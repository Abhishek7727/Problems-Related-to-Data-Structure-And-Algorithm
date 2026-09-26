class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        queue<pair<string,int>>q;
        if(!word.count(endWord))
        return 0;
        q.push({beginWord,1});
        vis.insert(beginWord);
        while(!q.empty())
        {
            auto[state,dist]=q.front();
            q.pop();

            if(state==endWord)
            return dist;
            for(int i=0;i<state.size();i++)
            {
              string next=state;
             for(char ch='a';ch<='z';ch++)
              {
                   next[i]=ch;
                   if(word.count(next) && !vis.count(next))
                   {
                    vis.insert(next);
                    q.push({next,dist+1});
                   }
              }
            }
        }
        return 0;

        
    }
};