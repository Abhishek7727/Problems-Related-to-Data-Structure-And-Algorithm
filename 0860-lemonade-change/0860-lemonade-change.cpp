class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            else if(bills[i]==10)
            {
                if(five==0)
                return false;
                five--;
                ten++;
            }
            else
            {
                if(ten>0)
                {
                    ten--;
                    if(five==0)
                    return false;
                    else
                    five--;
                }
                else
                {
                    if(five<3)
                    return false;
                    five=five-3;
                }
            }
        }
        return true;
        
    }
};