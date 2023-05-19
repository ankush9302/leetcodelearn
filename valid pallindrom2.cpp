
#include<bits/stdc++.h>
using namespace std;
void f(int a,int b)
{
    cout<<a<<b<<endl;
}
int main(){
 int i=0,j=8;
 while(i<=j)
 {
    f(j--,i);
    cout<<j<<i<<endl;
    i++;j--;
 }
}