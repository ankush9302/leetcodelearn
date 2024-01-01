#include <bits/stdc++.h>
using namespace std;
void solve(int o,int c,string op,vector<string>&ans)
{
    if(c==0&&o==0)
    {
        ans.push_back(op);
        return ;
        
    }
    if(o!=0)
    {
        string op1=op;
        op1.push_back('(');
        solve(o-1,c,op1,ans);
    }
    if(c>o)
    {
          string op2=op;
        op2.push_back(')');
        solve(o,c-1,op2,ans);
    }
}
vector<string>generateParenthesis(int A)
 {
      vector<string>ans;
    int open=A;
    int close=A;
    string op="";
    solve(open,close,op,ans);
    return ans;
    
}
int main() {
	int s;
	cin>>s;
	
	vector<string> ans=generateParenthesis(s);
    for(auto it:ans)
    cout<<it<<" ";
	return 0;
}