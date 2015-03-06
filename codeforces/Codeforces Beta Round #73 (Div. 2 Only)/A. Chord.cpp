#include<bits/stdc++.h>

using namespace std;

map<string, int> m;

int distancia(string a, string b)
{
    int tmp = m[b]-m[a];
    if(  tmp > 0)return tmp;

    return tmp+12;
}

bool cmp(string a, string b)
{
    return m[a]<m[b];
}
int main()
{
    m["C"]  = 1;
    m["C#"] = 2;
    m["D"]  = 3;
    m["D#"] = 4;
    m["E"]  = 5;
    m["F"]  = 6;
    m["F#"] = 7;
    m["G"]  = 8;
    m["G#"] = 9;
    m["A"]  = 10;
    m["B"]  = 11;
    m["H"]  = 12;

    string n[3];
    cin>>n[0]>>n[1]>>n[2];
    sort(n, n+3, cmp);

    if(distancia(n[0],n[1])==3)
    {
        if(distancia(n[1],n[2]) == 4){
            if(distancia(n[0],n[2]) == 7){
                cout<<"minor"<<endl;
                return 0;
            }
        }
    }
    if(distancia(n[1],n[2])==3)
    {
        if(distancia(n[2],n[0]) == 4){
            if(distancia(n[1],n[0]) == 7){
                cout<<"minor"<<endl;
                return 0;
            }
        }
    }
    if(distancia(n[2],n[0])==3)
    {
        if(distancia(n[0],n[1]) == 4){
            if(distancia(n[2],n[1]) == 7){
                cout<<"minor"<<endl;
                return 0;
            }
        }
    }
    if(distancia(n[0],n[1])==4)
    {
        if(distancia(n[1],n[2]) == 3){
            if(distancia(n[0],n[2]) == 7){
                cout<<"major"<<endl;
                return 0;
            }
        }
    }
    if(distancia(n[1],n[2])==4)
    {
        if(distancia(n[2],n[0]) == 3){
            if(distancia(n[1],n[0]) == 7){
                cout<<"major"<<endl;
                return 0;
            }
        }
    }
    if(distancia(n[2],n[0])==4)
    {
        if(distancia(n[0],n[1]) == 3){
            if(distancia(n[2],n[1]) == 7){
                cout<<"major"<<endl;
                return 0;
            }
        }
    }
    cout<<"strange"<<endl;
    return 0;
}
