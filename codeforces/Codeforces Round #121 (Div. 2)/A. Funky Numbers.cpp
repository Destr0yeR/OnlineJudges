#include<bits/stdc++.h>

using namespace std;

long long triangular(int x)
{
    return (x*(x+1));
}

int main()
{
    long long n, tmp, a, b, aux;
    cin>>n;
    n *= 2;
    tmp = sqrt(n);

    bool encontrado = false;

    for(a = 1 ; a <= tmp ; ++a){
        aux = n - triangular(a);
        b = int(floor(sqrt(aux)));
        if(triangular(b) == aux){
            encontrado = true;
            break;
        }
    }

    if(triangular(a)+triangular(b) == n && a != 0 && b != 0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
