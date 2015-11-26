#include<bits/stdc++.h>

#define MAX 1001

using namespace std;

int a[MAX];

int main(){
    int n;
    bool positive, printed;
    while(scanf("%d",&n)&& n){
		positive = false;
		printed = false;
		for(int i = 0 ; i < n ; ++i){
			scanf("%d", &a[i]);
			if(a[i] > 0)positive = true;
		}
		
		if(positive){
			for(int i = 0 ; i < n ; ++i){
				if(a[i] > 0){
					if(printed)printf(" ");
					printf("%d", a[i]);
					printed = true;
				}
			}
			printf("\n");
		}
		else printf("0\n");
    }
 
 return 0;   
}
