class Solution {
public:
    int strStr(string str, string str1) {
       
       size_t found = str.find(str1);
        if (found != string::npos)
        return found;
        return -1;
        
    }
};