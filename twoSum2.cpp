#include<bits/stdc++.h>
using namespace std;
class Solution
 {
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
     {
        int n=numbers.size()-1;
        int i=0,j=n;
       
             cout<<i<<" " <<j<<endl;
            while(i<j)
            {   if(numbers[i]+numbers[j]==target)
                 {    cout<<numbers[i]<<numbers[j]<<endl;
                      return {i,j};
                     
                  }
                
                else if(numbers[i]+numbers[j]>target)
                     j--;
                else if(numbers[i]+numbers[j]<target)
                     i++;
            }

       
        cout<<i<<" " <<j;
     }
 };
int main()
{
  vector<int> arr={5,25,75};
  vector<int> arr2={2,7,11,15};
 
  Solution obj;
obj. twoSum(arr,100);
cout<<"case 2"<<endl;
obj. twoSum(arr2,9);
  return 0;  
}