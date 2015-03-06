#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int state = -1;
    int total = 0;
    for(int i = 0 ; i < n ; ++i){
        string p;
        cin>>p;
        switch(state)
        {
            case -1:
                if(p[1] == '0')state = 0;
                else state = 1;
                total++;
                break;
            case 0:
                if(p[1] == '1')
                {
                    state = 1;
                    total++;
                }
                break;
            case 1:
                if(p[1] == '0')
                {
                    state = 0;
                    total++;
                }
                break;
        }
    }
    cout<<total<<endl;
    return 0;
}
