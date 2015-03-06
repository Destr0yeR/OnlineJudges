#include<bits/stdc++.h>

using namespace std;
struct par{
    int price;
    int quality;

    bool operator<(const par &p)const{
        return price < p.price;
    }
};
int main()
{
    par laptop[100005];
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>laptop[i].price>>laptop[i].quality;
    }
    sort(laptop, laptop + n);

    bool happy = false;

    for(int i = 0 ; i < n - 1 ; ++i){
        if(laptop[i].quality > laptop[i+1].quality)
        {
            happy = true;
            break;
        }
    }
    cout<<(happy?"Happy":"Poor")<<" Alex"<<endl;
    return 0;
}
