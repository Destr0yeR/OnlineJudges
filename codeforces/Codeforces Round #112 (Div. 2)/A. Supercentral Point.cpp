#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x;
    int y;
}point[201];

int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>point[i].x>>point[i].y;
    }
    int total = 0;
    for(int i = 0 ; i < n ; ++i){
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        for(int j = 0 ; j < n ; ++j){
            if(i!=j){
                //cout<<point[i].x<<" "<<point[j].x<<" "<<point[i].y<<" "<<point[j].y<<endl;
                if(point[i].x == point[j].x){
                    if(point[i].y < point[j].y)up++;
                    if(point[i].y > point[j].y)down++;
                }
                if(point[i].y == point[j].y){
                    if(point[i].x < point[j].x)right++;
                    if(point[i].x > point[j].x)left++;
                }
            }
        }
        //cout<<up<<" "<<down<<" "<<right<<" "<<left<<endl;
        if(up>0 && down>0 && right>0 && left>0)total++;
    }

    cout<<total<<endl;
    return 0;
}
