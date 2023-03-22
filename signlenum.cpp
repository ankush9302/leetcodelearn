#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts) 
    {int cnt=0,maxi=INT_MIN,flag=0;
        for(int i=0;i<forts.size();i++)
        {
            if(forts[i]==1||forts[i]==-1)
            {maxi=max(cnt,maxi);
            cout<<cnt<<" "<<maxi<<endl;
                cnt=0;
                flag=1;
            }
             if(forts[i]==0&&flag==1)
            {
               cnt++;
                 
               
            }
        }
        return maxi;
    }
};
int main()
{
  vector<int> arr={1,0,0,-1,0,0,0,0,1};
 
  Solution obj;
 cout<< obj.captureForts(arr);
  return 0;  
}