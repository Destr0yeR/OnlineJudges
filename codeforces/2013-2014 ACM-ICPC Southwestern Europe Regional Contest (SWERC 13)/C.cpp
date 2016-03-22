#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX 201

using namespace std;

pair<double,pair<double,double> > P[MAX];

double A[MAX][MAX];
int mat[MAX][MAX];

void print(int a, int b)
{
    if(mat[a][b]==-1)
    {
        printf("%d ", b);
        return;
    }
    print(a, mat[a][b]);
    print(mat[a][b], b);
}

double cuad(double x){return x*x;}

double dist(pair<double,pair<double,double> > a, pair<double,pair<double,double> > b)
{
	double x1, y1, x2, y2, z1, z2;
	
	x1 = a.first;
	y1 = a.second.first;
	z1 = a.second.second;
	
	x2 = b.first;
	y2 = b.second.first;
	z2 = b.second.second;
	
    return sqrt(cuad((x1-x2)*5) + cuad(y1-y2) + cuad(z1-z2));
}

int main()
{
	int n, m;
    mset(mat, -1);
    forn(i, MAX)forn(j, MAX)A[i][j]=1e12;
    sii(n, m);
    
    forn(i, n){
        cin >> P[i].first >> P[i].second.first >> P[i].second.second;
        A[i][i]=0;
    }
    
    int a, b;
    string s;
    forn(i, m){
        sii(a, b);
        cin>>s;
        if(s=="walking" || s=="stairs")A[a][b] = A[b][a] = dist(P[a], P[b]);
        else if(s=="lift")A[a][b] = A[b][a] = 1;
        else
        {
            A[a][b] = 1;
            A[b][a] = dist(P[a], P[b])*3;
        }
    }
    
    forn(k, n){
        forn(i, n){
            forn(j, n){
                if(A[i][j] > A[i][k] + A[k][j])
                {
                    mat[i][j] = k;
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    
    int Q;
    si(Q);
    forn(q, Q){
        sii(a, b);
        printf("%d ", a);
        print(a,b);
        puts("");
    }
    
    return 0;
}




