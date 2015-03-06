#include<bits/stdc++.h>

using namespace std;

int main(){
       int t, n, i, a[50];
       cin>>t;
       while(t--)
       {
               cin>>n;
               int cnt = 0;
               for(i=0; i<n; i++)
               {
                    cin>>a[i];
                    if(a[i]==1)
                        cnt++;
               }
               if(cnt==n)
               {
                    if(n&1)
                        cout<<"Brother"<<endl;
                    else
                        cout<<"Jhon"<<endl;
               }
               else
               {
                    for(i=1; i<n; i++)
                        a[0]^=a[i];
                    if(a[0]==0)
                        cout<<"Brother"<<endl;
                    else
                        cout<<"Jhon"<<endl;
               }
       }
       return 0;
}
