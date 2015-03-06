#include<bits/stdc++.h>

using namespace std;

int main()
{
    string say;
    cin>>say;
    transform(say.begin(), say.end(), say.begin(), ::tolower);
    int state = 0;

    for(int i = 0 ; i < say.size() ; ++i)
    {
        switch(state)
        {
        case 0:
            if(say[i] == 'h')state = 1;
            break;
        case 1:
            if(say[i] == 'e')state = 2;
            break;
        case 2:
            if(say[i] == 'l')state = 3;
            break;
        case 3:
            if(say[i] == 'l')state = 4;
            break;
        case 4:
            if(say[i] == 'o')state = 5;
            break;
        }
    }
    cout<<(state == 5? "YES":"NO")<<endl;

    return 0;
}
