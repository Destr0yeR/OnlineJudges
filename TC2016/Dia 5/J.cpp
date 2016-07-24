#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define sz(x) (int)x.size()

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#ifdef ONLINE_JUDGE
	#define sll(x) scanf("%I64d", &x)
#else
	#define sll(x) cin >> x
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

#define MAX 60001

struct Point{
  double x,y;
  Point(double X=0.0,double Y=0.0){
    x=X;
    y=Y;
  }
  Point operator+(const Point &A)const{
    return Point(A.x+x,A.y+y); 
  }
  Point operator-(const Point &A)const{
    return Point(x-A.x,y-A.y);
  }
  double operator*(const Point &A)const{//Producto escalar
    return x*A.x+y*A.y;
  }
  double operator^(const Point &A)const{//Producto vectorial
    return x*A.y-y*A.x;
  }
  bool operator==(const Point &A)const{
    return (x==A.x && y==A.y);
  }
  bool operator<(const Point &A)const{
    if(x==A.x) return y<A.y;
    return x<A.x;
  }
};
struct Line{
  Point Start,End;
  Line(Point A=Point(0.0,0.0),Point B=Point(0.0,0.0)){
    Start=A;
    End=B;
  }
  bool operator==(const Line &A)const{
    return ((Start==A.Start && End==A.End)||(Start==A.End && End==A.Start));
  }
};
double signed_AreaTriangulo(Point A,Point B,Point C){
  return ((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y))/2;
}
double norma(const Point &A){
    return sqrt(A*A);
}
double distancia(const Point &A,const Point &B){
  //distancia de un punto a otro
  return norma(A-B);
}
double direction(Point A,Point B,Point C){//direccion del vector
  return (C-A)^(B-A);
}
bool onsegment(Point A,Point B,Point C){
  if(min(A.x,B.x)<=C.x && C.x<=max(A.x,B.x) && min(A.y,B.y)<=C.y && C.y<=max(A.y,B.y)){
    return true;
  }
  return false;
}
bool prolong(Line A,Line B){//verifica si dos segmentos de rectas pertecen a la misma recta
  if(direction(B.Start,B.End,A.Start)==0) return true;
  if(direction(B.Start,B.End,A.End)==0) return true;
  if(direction(A.Start,A.End,B.Start)==0) return true;
  if(direction(A.Start,A.End,B.End)==0) return true;
  return false;
}
bool isParalle(Line A,Line B){//verifica si dos rectas son paralelas
  return (((A.Start.x-A.End.x)*(B.Start.y-B.End.y)-(A.Start.y-A.End.y)*(B.Start.x-B.End.x))!=0);
}
bool inter(Line A,Line B){//verifica si dos rectas se intersectan
  double d1,d2,d3,d4;
  d1=direction(B.Start,B.End,A.Start);
  d2=direction(B.Start,B.End,A.End);
  d3=direction(A.Start,A.End,B.Start);
  d4=direction(A.Start,A.End,B.End);
  if(((d1>0&&d2<0)||(d1<0&&d2>0)) && ((d3>0&&d4<0)||(d3<0&&d4>0)))
    return true;
  if(d1==0 && onsegment(B.Start,B.End,A.Start))
    return true;
  if(d2==0 && onsegment(B.Start,B.End,A.End))
    return true;
  if(d3==0 && onsegment(A.Start,A.End,B.Start))
    return true;
  if(d4==0 && onsegment(A.Start,A.End,B.End))
    return true;
  return false;
}

#define PB(a) push_back(a)
#define mp(a, b) make_pair(a, b)

#define from Start
#define to End

vector<Line> h1, h2, v1, v2;

bool cmpH(Line a, Line b){
	return a.Start.x < b.Start.x;
}

bool cmpV(Line a, Line b){
	return a.Start.y < b.Start.y;
}

bool isH(Line &x){
	if(x.from.x == x.to.x){
		if(x.from.y > x.to.y)swap(x.from.y, x.to.y);
		return false;
	}
	if(x.from.x > x.to.x)swap(x.from.x, x.to.x);
	return true;
}

void read1(){
	Point p, q, l;
	int m;
	double fi, se;
	Line linea;
	
	si(m);
	cin >> fi >> se;
	l = p = Point(fi, se);
	forr(i, 1, m){
		cin >> fi >> se;
		q = Point(fi, se);
		linea = Line(p, q);
		if(isH(linea))h1.PB(linea);
		else v1.PB(linea);
		p = q;
	}
	linea = Line(l, q);
	if(isH(linea))h1.PB(linea);
	else v1.PB(linea);
}

void read2(){
	Point p, q, l;
	int m;
	double fi, se;
	Line linea;
	
	si(m);
	cin >> fi >> se;
	l = p = Point(fi, se);
	forr(i, 1, m){
		cin >> fi >> se;
		q = Point(fi, se);
		linea = Line(p, q);
		if(isH(linea))h2.PB(linea);
		else v2.PB(linea);
		p = q;
	}
	linea = Line(l, q);
	if(isH(linea))h2.PB(linea);
	else v2.PB(linea);
}

void outlin(Line curr){
	cout << curr.from.x << " " << curr.from.y << " : " << curr.to.x << " " << curr.to.y << endl;
}

struct compare(){
	bool operator()(const Line &a, double l){
		return a.
	}
}

int f(vector<Line> h, vector<Line> v){
	int ans = 0;
	int l, r;
	
	vector<Line>::iterator low, up;
	
	cout << "start" << endl;
	forn(i, sz(v)){
		cout << i << " ::: ";
		outlin(v[i]);
		l = bin(h ,v[i].from.y);
		outlin(h[l]);
		r = bin(h ,v[i].to.y);
		ans += abs(l-r);
		outlin(h[r]);
	}
	cout << "end" << endl;
	
	return ans;
}

int main(){	
	read1();
	sort(all(h1), cmpH);
	cout << endl;
	sort(all(v1), cmpV);
	read2();
	sort(all(h2), cmpH);
	sort(all(v2), cmpV);
	
	cout << (f(h1, v2) + f(h2, v1)) << endl;
	
	return 0;
}
