#define N 200007
#define pii pair<int,int>
#include <bits/stdc++.h>
using namespace std;

int f[N],g[N],a[N],b[N];
vector<pii> res;
int main()
{
    int n,x;
    int c1=0,c2=0;
    cin>>n;
    for(int i=1;i<N;i++)
        f[i]=g[i]=N;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==1)
            f[++c1]=i;
        else
            g[++c2]=i;
        a[i]=c1,b[i]=c2;
    }

    for(int t=1;t<=n;t++)
    {
        int sa=0,sb=0;
        int pa=0,pb=0,flag=1;
        for(int cur=0;cur<n;)
        {
            int x=f[pa+t],y=g[pb+t];
            if(min(x,y)==N)
            {
                flag=0;
                break;
            }
            cur=min(x,y);
            if(cur==n)
            {
                if((x<y && sa<sb) || (x>y && sb<sa))
                {
                    flag=0;
                    break;
                }
            }
            if(x<y) sa++;
            else sb++;
            pa=a[cur],pb=b[cur];
        }
        if(flag)
            res.push_back(make_pair(max(sa,sb),t));
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
        printf("%d %d\n",res[i].first,res[i].second);
    return 0;
}
