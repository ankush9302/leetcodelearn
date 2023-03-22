#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {            // Dutch National Flag Algo.
        int i=0,j=0,k=nums.size()-1;
        while(i<=k){                                // One pass
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==1)
            {
                i++;
            }
            else{
                swap(nums[i],nums[k]);
                k--;
            }
        }
        for (int i = 0; i < nums.size(); i++)
       {
        cout<<nums[i]<<" ";
        }


    }
    
    
};

// TC: O(n) SC: O(1)
// Try yourself with 0 1 2 0 1 2 using this algo to understand it fully :)

int main()
{
  vector<int> arr={0,1,0,2,1,1};

  Solution obj;
  obj.sortColors(arr);
  return 0;  
}


/* class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0,two=0,zero=0;
        for(int i=0;i<nums.size();i++){     //O(n)
           if(nums[i]==0)
               zero++;
            else if(nums[i]==1)
                one++;
            else
                two++;
        }
        nums.clear();                       //O(n)
        for(int i=0;i<zero;i++)             ///
            nums.emplace_back(0);           
        for(int i=0;i<one;i++)              ///  All 3 for loops altogether O(n)
            nums.emplace_back(1);
        for(int i=0;i<two;i++)              ///
            nums.emplace_back(2);
    }
};
//Total TC:O(n) SC:O(1)*/
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {         //One pass
        int j = 0, k = nums.size()-1;
        for (int i=0; i <= k; i++) {                //O(n)
            if (nums[i] == 0)
                swap(nums[i], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i--], nums[k--]);
        }
    }
};
// Total TC:O(n) SC:*/