#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {  int n=matrix.size();

      cout<<"value of n="<<n<<" ";
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
              swap(matrix[i][j],matrix[j][i]);
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
              swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }

         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        
    }
};

int main()
{
  vector<vector<int>> arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 
  Solution obj;
  obj.rotate(arr);
  return 0;  
}