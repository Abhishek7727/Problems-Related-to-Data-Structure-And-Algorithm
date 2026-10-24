class Solution {
public:
    int dayNumber(string date)
    {

        int m=stoi(date.substr(0, 2));
         int d=stoi(date.substr(3, 2));


        vector<int>month={ 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31};

         

         int days=0;
         for(int i=0;i<m-1;i++)
         {
            days+=month[i];
         }   
         return days+d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int startA=dayNumber(arriveAlice);
        int endA=dayNumber(leaveAlice);
        int startB=dayNumber(arriveBob);
        int endB=dayNumber(leaveBob);

        int start=max(startA,startB);
        int end=min(endA,endB);

        return max(0,end-start+1);
        
    }
};