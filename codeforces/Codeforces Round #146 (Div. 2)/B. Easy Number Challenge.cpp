#include<bits/stdc++.h>

#define N 2000000
#define MOD 1073741824
using namespace std;

int cnt[N];

int main()
{
    int a,b,c,ans,i,j,k,n;

    cin >> a >> b >> c;
    n=a*b*c;
    memset(cnt,0,sizeof(cnt));
    
    for (i=1;i<=n;i++){
        for (j=i;j<=n;j+=i)cnt[j]++;
	}

    ans=0;
    for (i=1;i<=a;i++){
        for (j=1;j<=b;j++){
            for (k=1;k<=c;k++){
                ans+=cnt[i*j*k];
                ans%=MOD;
            }
		}
	}
	
    cout << ans << "\n";

    return 0;
}
