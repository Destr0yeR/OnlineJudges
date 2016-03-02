#include<bits/stdc++.h>

using namespace std;

int cnt[10];  
  
int main()  
{  
    int i=0, j, flag=0, sum=0, v=0, s;  
    char ch;
    
    while(scanf("%c",&ch) != EOF  &&  ch != '\n'){
		cnt[ch-'0']++;
		sum += ch-'0';
	}
    
    sum %= 3;
    
    if(!cnt[0] && !cnt[5]) printf("impossible\n");
    else{  
        if(!cnt[0]) cnt[5]--, flag=1;  
        if(sum) {  
            s = sum;  
            if(cnt[sum] + cnt[sum+3] + cnt[sum+6]==0) s=3-sum;
            
            for(i = s ; i < 9 ; i += 3){  
                if(cnt[i]){
					cnt[i]--;
					sum = (sum + 3 - s%3)%3;
				}
                if(cnt[i] && sum){
					cnt[i]--;
					sum=0;
				}
                if(!sum) break;  
            }
        }
        
        for(j = 1 ; j < 10 ; ++j)v += cnt[j];
       
        if(v==0||i>=9){
            if(cnt[0]) printf("0\n");
            else printf("impossible\n");
            return 0;
        }
        
        for(i = 9 ; i >= 0 ; --i){  
            j=cnt[i]; 
            while(j--)printf("%d",i);  
        }
        
        if(flag) printf("5");
        printf("\n");
    }  
    return 0;  
} 
