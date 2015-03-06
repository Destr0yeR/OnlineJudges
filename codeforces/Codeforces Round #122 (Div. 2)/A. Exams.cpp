#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d",&n, &k);
    int rpta = 3*n - k;

    if(rpta<0)printf("0\n");
    else printf("%d",rpta);
    return 0;
}
