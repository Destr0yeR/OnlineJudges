#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("input.txt", "r", stdin);
    #endif
    int x, y;
    cin >> x >> y;
    if(!x && !y) cout << 0 << endl;
    else if(y <= 0 && y < x && x <= -y + 1)
        cout << 4 * (-y) << endl;
    else if(x > 0 && -x < y && y <= x)
        cout << 1 + 4 * (x - 1) << endl;
    else if(y > 0 && -y <= x && x < y)
        cout << 2 + 4 * (y - 1) << endl;
    else
        cout << 3 + 4 * (-x - 1) << endl;
    return 0;
}
