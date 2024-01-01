#include <bits/stdc++.h>
using namespace std;
   int longestValidParentheses(string s)
{
    queue<char> q1;
    stack<char> s2;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        q1.push(s[i]);
    if (q1.empty())
        return 0;
    s2.push(q1.front());
    q1.pop();
    while (!q1.empty())
    {
        while (!q1.empty() && !s2.empty())
        {
            if (q1.front() == ')' && s2.top() == '(')
            { 
                q1.pop();
              s2.pop();
                ans=ans+2;
            }

            else
            { ans=0;
              s2.pop();
              break;
            }
           
          
              
        }
        if (q1.empty())
        {
            break;
        }

        s2.push(q1.front());
        q1.pop();
    }
    return ans;
}




int main()
{
    string s;
    cin>>s;
    cout<<longestValidParentheses(s);
    return 0;
}