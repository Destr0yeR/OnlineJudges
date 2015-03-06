#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> m;
    string s;
    cin>>s;
    for(int i = 0 ; i < s.size(); ++i)m[s[i]]++;

    int n = m['n'];
    int i = m['i'];
    int e = m['e'];
    int t = m['t'];

    n = (n-1)/2;
    e /= 3;

    int min = 1000;

    if(n<min)min=n;
    if(i<min)min=i;
    if(t<min)min=t;
    if(e<min)min=e;

    cout<<min<<endl;

    return 0;
}
