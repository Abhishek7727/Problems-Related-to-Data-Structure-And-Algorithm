class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    bool flag=false;
                    for(int k=0;k<n;k++)
                    {
                       if( mat[k][j]==1 & k!=i)
                       {
                        flag=true;
                        break;
                       }
                      
                    }

                     if(flag==false)
                       {
                        for(int k=0;k<m;k++)
                         {
                            if(mat[i][k]==1 &&k!=j)
                            {
                                flag=true;
                                break;
                            }
                         }
                       }

                       if(flag==false)
                       {
                        count++;
                       // i=i+1;
                        
                       }
                }
            }
        }
        return count;
        
    }
};