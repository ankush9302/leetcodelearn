class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int>positive;
        vector<int>negative;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            negative.push_back(nums[i]);
             if(nums[i]>0)
            positive.push_back(nums[i]);
        }
         for(int i=0,j=0,k=0;i<nums.size();i++)
         { if(i%2==0)
           nums[i]=positive[j++];
           if(i%2!=0)
           nums[i]=negative[k++];
         }
         return nums;
        
    }
};             //this is the brute force approch


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int>ans;
        
       
         for(int i=0,j=0,k=1;i<nums.size();i++)
         { if(nums[i]>=0)
          ans[j+=2]=nums[i];
           if(nums[i]<0)
           ans[k+=2]=nums[i];           
         }
         return ans;
        
    }
};                  //this is optimal as possible