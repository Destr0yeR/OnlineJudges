#include<bits/stdc++.h>

using namespace std;

bool comparasion(int x, int y){return x > y;}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> scores(n);
    while(n--)
    {
        int score;
        cin>>score;
        scores.push_back(score);
    }

    int total = 0;

    sort(scores.begin(), scores.end(), comparasion);

    for(vector<int>::iterator it = scores.begin() ; it != scores.end() ; ++it)
    {
        if(*it >= scores[k-1] && *it > 0)
        {
            total++;
        }
    }
    cout<<total<<endl;
    return 0;
}
