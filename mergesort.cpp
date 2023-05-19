//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    { cout<<"recieved value"<<l<<" "<<mid<<" "<<r<<endl;
    for(int i=l;i<=r;i++)
        {  
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        vector<int > temp;
        int left=l;
        int rigth=mid+1;
        while(left<=mid&&rigth<=r)
        {
            if(arr[left]<=arr[rigth])
            { cout<<"pushing value inside if"<<arr[left]<<endl;
                temp.push_back(arr[left]);
                left++;
            }
            else
            {  cout<<"pushing value inside else"<<arr[rigth]<<endl;
                temp.push_back(arr[rigth]);
                rigth++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
         while(rigth<=r)
        {
            temp.push_back(arr[rigth]);
        rigth++;
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i-l];
        }cout<<"inside merge"<<endl;
        for(int i=l;i<=r;i++)
        {  
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {   if(l==r)
       return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr ,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    // int n,T,i;

    // scanf("%d",&T);

    // while(T--){
    
    // scanf("%d",&n);
    // int arr[n+1];
    // for(i=0;i<n;i++)
    //   scanf("%d",&arr[i]);
    int arr[]={4 ,1 ,3 ,9, 7};

    Solution ob;
    ob.mergeSort(arr, 0, 4);
    printArray(arr, 4);
    
    return 0;
}
// } Driver Code Ends