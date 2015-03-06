#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int pr = 0;
    int ma = 0;
    int pe = 0;

    int m[5000][4];

    for(int i = 1 ; i <= n ; ++i){
        int a;
        cin>>a;
        if(a == 1){
            m[pr][1] = i;
            pr++;
        }
        else if(a == 2){
            m[ma][2] = i;
            ma++;
        }
        else if(a == 3){
            m[pe][3] = i;
            pe++;
        }
    }

    int total = min(pr, min(ma, pe));

    cout<<total<<endl;

    if(total != 0){
        for(int i = 0 ; i < total ; ++i){
            cout<<m[i][1]<<" "<<m[i][2]<<" "<<m[i][3]<<endl;
        }
    }

    return 0;
}
