#include<bits/stdc++.h>

using namespace std;

int main(){
	int T, N, W, p[102];
	scanf("%d",&T);
	
	while(T--){
		int Max=0;
		scanf("%d%d",&N,&W);
		
		for(int i=1;i<=N;i++)scanf("%d",&p[i]);
		
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				int ans=(W/p[i])*(p[j]-p[i]);
				if(Max<ans)Max=ans;
			}
		}
		printf("%d\n",Max);
	}
	return 0;
}
