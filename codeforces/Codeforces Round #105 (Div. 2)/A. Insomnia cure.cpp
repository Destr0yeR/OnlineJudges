#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int main()
{

    bool numb[MAX];
    int a[4], d;

    cin>>a[0]>>a[1]>>a[2]>>a[3]>>d;

    sort(a, a + 4);

    int cont = 0;
    for(int i = 1 ; i<= d ; ++i)numb[i] = false;

    for(int j = 0 ; j < 4 ; ++j){
        if(!numb[a[j]]){
            for(int i = a[j] ; i <= d ; i += a[j])
            {
                if(!numb[i])
                {
                    numb[i] = true;
                    cont++;
                }
            }
        }
    }

    cout<<cont<<endl;
    return 0;
}
