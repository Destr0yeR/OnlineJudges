#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string to_lower(string a)
{
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    return a;
}

int main()
{
    string a, b;
    cin>>a>>b;
    cout<< to_lower(a).compare(to_lower(b))<<endl;
    return 0;
}
