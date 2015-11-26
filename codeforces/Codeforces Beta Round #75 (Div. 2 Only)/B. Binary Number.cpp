#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;    
    cin >> s;
	
	int mid = 0;
    long cont = 0;

    for(int i = s.size() - 1; i >= 0; i--){
        if(mid == 0 && s[i] == '0')cont++;
        else if(mid == 1 && s[i] == '0')cont += 2;
        else if(s[i] == '1' && i > 0){
			cont++;
			mid = 1;
		}
        else if(s[i] == '1' && mid == 1)cont += 2;
    }

    cout << cont << '\n';

    return 0;
}
