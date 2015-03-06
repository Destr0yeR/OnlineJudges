#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, l, r, tmp;
    int menos=0, mas=0;

    scanf("%d%d", &n, &m);

    for(int i = 0 ; i < n ; ++i){
        scanf("%d",&tmp);
        if(tmp == -1)menos++;
        else mas++;
    }
    int mini = min(mas, menos)*2;
    while(m--){
        scanf("%d%d", &l, &r);
        int mid = r-l+1;
        if(mid%2 == 1)printf("0\n");
        else{
            if(mini>=mid)printf("1\n");
            else printf("0\n");
        }
    }

    return 0;
}
