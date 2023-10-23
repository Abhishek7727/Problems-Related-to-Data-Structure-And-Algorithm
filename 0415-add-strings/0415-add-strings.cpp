class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.length()-1,j=num2.length()-1;
        int carry=0;
        while(i>=0||j>=0||carry>0)
        {
            int sum=0;
            if(i>=0)
            sum+=(num1[i--]-'0');
            if(j>=0)
            sum+=(num2[j--]-'0');
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ans+=to_string(sum);

        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};