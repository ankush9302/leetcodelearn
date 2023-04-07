#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {

      
        int i;
        vector<pair<int ,int>>v(2);
        vector<int>ans;
        int n=nums.size();
        if(n==1)
         {ans.push_back(v[0].first);
         return nums;}
       if(n==2)
          {
            if(nums[0]==nums[1])
           { ans.push_back(nums[0]);
            return ans;}
            else
            return nums;
             }
        //to select a candidate with max occurance
       for (i = 0; i < n; i++)
       {
            if (nums[i]==v[0].first)
               {
                   v[0].second++;
               }
            else if (nums[i]==v[1].first)
               {
                   v[1].second++;
               }  
           else  if (v[0].second == 0) 
           {
            v[0].first= nums[i];
            v[0].second= 1;
           }
           else  if (v[1].second == 0) 
           {
            v[1].first= nums[i];
            v[1].second= 1;
           }
            else
                {
                    v[0].second--;
                    v[1].second--;
                }
        
    } 
    //cand selected                           
    int count1 = 0,count2=0;
    for (i = 0; i < n; i++) 
    {
        if (nums[i]==v[0].first)
         count1++;
         else if(nums[i]==v[1].first)
         count2++;
         
    }
    cout<<count1<<count2<<n/3<<v[0].first<<v[1].first<<endl;
 
    if (count1 > n / 3)
       ans.push_back(v[0].first);
    else if (count2 > n / 3)
       ans.push_back(v[1].first);
       cout<<ans[0]<<ans[1];
    return ans;
     return{-1};


        
        
    }
};

int main()
{
  vector<int> arr={3,2,2,2,3};
 
  Solution obj;
obj. majorityElement(arr);
  return 0;  
}