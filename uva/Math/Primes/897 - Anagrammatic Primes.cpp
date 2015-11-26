#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};   
    //freopen("897.in", "r", stdin);
    //freopen("897.out", "w", stdout);
    int n, max;
    
    while (scanf("%d", &n) == 1)
    {
		if(n == 0)break;
        if(n >= 991){
			printf("0\n");
		}
		else {
			int i = 0;
			while(a[i] <= n)i++;
			
			max = 1;
			
			while(n){
				n/=10;
				max*=10;
			}
			if(a[i] < max)printf("%d\n", a[i]);
			else printf("0\n");
		}
        
    }
}
