#include<bits/stdc++.h>
#define maxA 10000000

int n,m,a[510][510],ListSta[110],d[510],max;
bool IsSta[510];

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

void Enter()
{
    int i,j,x;
    char s[20];
    
    scanf("%d %d",&m,&n);
    for (i=1;i<=n;i++)
    {
        a[i][i]=0;
        for (j=i+1;j<=n;j++)
            a[i][j]=a[j][i]=maxA;
    }
    memset(IsSta,false,n+5);
    for (j=1;j<=m;j++)
    {
        scanf("%d",&i);
        IsSta[i]=true;
        ListSta[j]=i;
    }
    
    getchar();
    while (gets(s) && s[0]!='\0')
    {
        sscanf(s,"%d %d %d",&i,&j,&x);
        a[j][i]=a[i][j]=x;
    }
}

void Floyd()
{
    for (int k=1;k<=n;k++)
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
                a[u][v] = a[v][u] = min(a[u][v],a[u][k]+a[v][k]);
}

void TinhD()
{
    int i,j;
    max=0;
    for (i=1;i<=n;i++)
    {
        d[i]=maxA;
        for (j=1;j<=m;j++)
            if (a[i][ListSta[j]]<d[i])
                d[i]=a[i][ListSta[j]];
        if (d[i]>max)
            max=d[i];
    }
}

int Find()
{
    int i,j,tmpmax,vt=1;
    for (i=1;i<=n;i++)
    {
        tmpmax=0;
        if (!IsSta[i])
        {
            for (j=1;j<=n;j++)
            {
                int tmp=min(d[j],a[i][j]);
                if (tmp>tmpmax) tmpmax=tmp;
            }
            if (tmpmax<max)
            {
                max=tmpmax;
                vt=i;
            }
        }
    }
    return vt;
}

main()
{
    int time,rs;
    scanf("%d",&time);
    while (time-->0)
    {
        Enter();
        Floyd(); TinhD();
        rs=Find();
        printf("%d\n",rs);
        if (time>0) printf("\n");
    }
}
