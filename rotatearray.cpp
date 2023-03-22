#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
     void rotate(vector<int>& nums, int k)
     {
        int n=nums.size();
        while(k--)
        {
            int temp=nums[n-1];
            for(int i=n-1;i>=0;i--)
            {
                nums[i]=nums[i-1];

            }
            nums[0]=temp;
        }
        for(int i=0;i<n;i++)
            {
                cout<<nums[i]<<"";

            }
    }
};

int main()
{
  vector<int> arr={2,3,4,7,11};
  int k=3;
  Solution obj;
  obj.rotate(arr,k);
  return 0;  
}