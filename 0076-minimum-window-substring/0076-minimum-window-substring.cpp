class Solution {
public:
    string minWindow(string s, string t) {
        int start=-1;
        int len=INT_MAX;
        unordered_map<char,int>mp;
        for(char ch:t)
        {
            mp[ch]++;
        }
        int count=t.size();
        int m=mp.size();
        int i=0,j=0;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
               
                if(mp[s[j]]>0)
                count--;

                 mp[s[j]]--;
            }
            if(count>0)
            j++;
            else if(count==0)
            {
                if(len>j-i+1)
                {
                    len=j-i+1;
                    start=i;
                }
                while(count==0)
                {
                    if(mp.find(s[i])!=mp.end())
                    {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    count++;
                    
                    
                    }
                    if(len>j-i+1)
                {
                    len=j-i+1;
                    start=i;
                }
                    i++;
                    

                }
                j++;
            }
        }
        return (start==-1)? "":s.substr(start,len);

    }
};