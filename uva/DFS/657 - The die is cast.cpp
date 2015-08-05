#include <bits/stdc++.h>
using namespace std;

char pic[51][51];
int w, h;
void DFS_X(int, int);
void DFS_pixel (int i, int j, int &dots)
{
    if (pic[i][j] == 'X') {
        dots++;
        DFS_X(i, j);
    }
    pic[i][j] = '.';
    if (i+1 < h && pic[i+1][j] != '.') DFS_pixel(i+1, j, dots);
    if (i-1 >=0 && pic[i-1][j] != '.') DFS_pixel(i-1, j, dots);
    if (j+1 < w && pic[i][j+1] != '.') DFS_pixel(i, j+1, dots);
    if (j-1 >=0 && pic[i][j-1] != '.') DFS_pixel(i, j-1, dots);
}
void DFS_X (int i, int j)
{
    pic[i][j] = '*';
    if (i+1 < h && pic[i+1][j] == 'X') DFS_X(i+1, j);
    if (i-1 >=0 && pic[i-1][j] == 'X') DFS_X(i-1, j);
    if (j+1 < w && pic[i][j+1] == 'X') DFS_X(i, j+1);
    if (j-1 >=0 && pic[i][j-1] == 'X') DFS_X(i, j-1);
}
int main()
{
 //   freopen("input.txt","rt",stdin);
    int Case = 1;
    while (cin >> w >> h){
        if (!w && !h) break;

        getchar();
        for (int i = 0; i < h; i++)
            gets(pic[i]);

        int ans[100] = {0}, nOfans = 0;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (pic[i][j] == '*'){
                    DFS_pixel(i, j, ans[nOfans]);
                    nOfans++;
                }

        sort(ans, ans + nOfans);

        cout << "Throw " << Case++ << endl;
        for (int i = 0; i < nOfans; i++){
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl << endl;
    }
    return 0;
}
