#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int k;
    string s;

    cin >> k;
    cin >> s;
    vector<int> p;

    int cont = 0;
    int total;
    int i, j;

    i = j = 0;
    total = 0;
    for( ; i < s.size() && j < s.size(); ){
        total += s[j] - '0';
        cout << " i: " << i <<  " total: " << total << " j : " << j << endl;
        if(total < k){
            j++;
        }
        else if(total == k){
            cont++;
            if(j < s.size()-1){
                j++;
            }
            else{
                total -= (s[i] - '0');
                i++;
            }
        }
        else{
            total -= (s[i]-'0');
            total -= (s[j]-'0');
            i++;
        }
    }

    cout << cont << endl;

    return 0;
}
