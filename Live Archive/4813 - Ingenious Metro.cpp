#include<bits/stdc++.h>

using namespace std;

int mcd(int a, int b){
    int aux;

    while(b != 0){
        aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}

int main()
{
    //freopen("4813 - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t, q, _mcd, aux, a , b, initial;

    while(cin >> t >> q){
        if(t == 0 && q == 0)break;

        cin >> initial;
        initial*=2;
        _mcd = 0;

        for(int i = 1 ; i < t ; ++i){
            cin >> aux;
            aux*=2;
            _mcd = mcd(_mcd, abs(aux - initial));
        }

        for(int i = 0 ; i < q ; ++i){
            cin >> a >> b;
            if(i != 0) cout << " ";

            if( t == 1){
                if( a == b || a+b == initial) cout << "Y";
                else cout << "N";
            }
            else if( a == b) cout << "Y";
            else if(_mcd == 0){
                if(a == -b)cout << "Y";
                else cout << "N";
            }
            else{
                if((a-b)%_mcd == 0 || (a+b - initial)%_mcd ==0) cout << "Y";
                else cout << "N";
            }
        }
        cout << endl;
    }

    return 0;
}
