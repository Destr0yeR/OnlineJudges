#include<bits/stdc++.h>

using namespace std;

bool can(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}

int main(){
	int m, s, sum;
	string mini = "", maxi = "";
	
	cin >> m >> s;
	
	if(s == 0 && m > 1)
	{
		cout << "-1 -1" << endl;
	}
	else if(can(m,s)){
		sum = s;
		for (int i = 0; i < m; i++){
			for (int d = 0; d < 10; d++){
				if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
				{
					mini += char('0' + d);
					sum -= d;
					break;
				}
			}
		}
		sum = s;
		for (int i = 0; i < m; i++){
			for (int d = 9; d >=0 ; d--){
				if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
				{
					maxi += char('0' + d);
					sum -= d;
					break;
				}
			}
		}
		cout << mini << " " << maxi << endl;
	}
	else{
		cout << "-1 -1" << endl;
	}
	
	return 0;
}
