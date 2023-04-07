/*  -------------LEARNING AND RESOURCES-------------
que. link: https://leetcode.com/problems/majority-element/
# std::sort ---worst case time complexity o(nlogn)
# marge sort is the fastest algorithm with worst case time complexity of o(nlogn) but it uses extra space

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int i, candidate = -1, votes = 0;
        int n=nums.size();
        //to select a candidate with max occurance
       for (i = 0; i < n; i++) {
        if (votes == 0) {
            candidate = nums[i];
            votes = 1;
        }
        else {
            if (nums[i] == candidate)
                votes++;
            else
                votes--;
        }
    } //cand selected                           
    int count = 0;
    for (i = 0; i < n; i++) {
        if (nums[i] == candidate)
            cout<<count++;
    }
 
    if (count = n / 2)
        return candidate;
    return -1;


        
    }
};

int main()
{
  vector<int> arr={2,2,2,1,1,4,3};
 
  Solution obj;
  cout<<obj.majorityElement(arr);
  return 0;  
}