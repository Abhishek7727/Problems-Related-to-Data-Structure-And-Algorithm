class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
     //unordered_map<String,int>mp1,mp2;
     if(s1==s2)
     return true;
     int l=0,r=s1.size()-1;
     while(s1[l]==s2[l])
     l++;
     while(s1[r]==s2[r])
     r--;
     swap(s2[r],s2[l]);
     return s1==s2;
    } 
};