#include<bits/stdc++.h>
#define pi acos(-1.0)
#define MAX 1 << 15
using namespace std;
 
bool mark [N];
bitset<MAX> b;
vector<int> p;
 
void sieve ()
{
    b.set();
 
    b[0] = b[1] = 0;
 
    for(int i = 4; i < MAX; i += 2)b[i] = 0;
 
    for(int i = 3; i * i <= MAX; i += 2){
        if(b[i] == 1){
            for(int j = i * i; j < N; j += 2 * i)
                b [j] = 0;
        }
    }
 
    p.clear ();
    p.push_back (2);
 
    for(int i = 3; i < N; i += 2){
        if(b[i] == 1){
			p.push_back (i);
		}
    }
}
 
void print (int here, int there)
{
    printf ("%d", primeList [here]);
 
    for ( int i = here + 1; i <= there; i++ )
        printf (" %d", primeList [i]);
    printf ("\n");
}
 
int main ()
{
    sieve ();
 
    int x, y;
 
    while(scanf ("%d %d", &x, &y) == 2) {
        if(x == 0 && y == 0)break;
 
        if(x > y)swap (x, y);
 
        int i = 0;
 
        while(p[i] < x)i++;
 
        while(p[i + 2] <= y){
            if(p[i + 2] - p[i + 1] == p[i + 1] - p[i]){
                int startIndex = i;
                int endIndex = i + 2;
                int diff = p[i + 1] - p[i];
                while(i + 3 < p.size () && p[i + 3] - p[i + 2] == diff){
                    endIndex++;
                    i++;
                }
 
                if(p[endIndex] <= y){
                    if (startIndex == 0 || p[startIndex] - p[startIndex - 1] != diff)
                        print (startIndex, endIndex);
                }
                else break;
            }
            i++;
        }
    }
 
    return 0;
}
