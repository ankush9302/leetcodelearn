#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> slicing(vector<int>& arr,int X, int Y)
{   auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
    vector<int> result(Y - X + 1);
    copy(start, end, result.begin());
    return result;
}
vector<int> twoSum( vector<int> &arr, int target) {
    int n=arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {moreNeeded, arr[i]};
        }
        mpp[num] = i;
    }
   return {INT16_MIN,INT16_MIN};
}
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {   int n=nums.size();
        vector < vector < int >> ans;
        set<vector<int>> ans1;
  vector < int > temp;
  int i, j, k,l;
 for(l=0;l<nums.size()-1;l++) {
  for (i = l+1; i < nums.size() ; i++) 
  {  int sum=0;
     sum=target-(nums[l]+nums[i]);
      vector<int> ans2;
     ans2=slicing(nums,i+1,n);
     temp=twoSum(ans2,sum);
     long long int sumtemp=temp[0]+temp[1];
      if (nums[l]+nums[i]+sumtemp==target)
      {cout<<"andar"<<endl;
        temp.push_back(nums[i]);
        temp.push_back(nums[l]);
      }
       
        
        
        if (temp.size() != 0)
          ans1.insert(temp);
    
  }
 }
 for(auto it:ans1)
 {
   ans.push_back(it);
 }
  vector < vector < int >> result;
  for (int i = 0; i < ans.size(); i++)
 { if(ans[i].size()==4)
    result.push_back(ans[i]);
 }

  return result;
        
    }
};


int main()
{
    Solution obj;
    vector<int> v{0,0,0,0};
    
    vector<vector<int>> sum=obj.fourSum(v,0);
    cout<<"The unique quadruplets are"<<endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}