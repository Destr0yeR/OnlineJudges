#include<bits/stdc++.h>
#define MAX 18
#define identity 0

using namespace std;

int A[1<<(MAX-1)], n;

int gcd(int a, int b) {
    if(b>a) swap(a,b);
    while(b!=0) {
        a=a%b;
        swap(a,b);
    }
    return a;
}

struct node{
	int val;	
}tree[1<<MAX];

struct info{
	int posi, q;
};

map<int, info> m;

void build(int root, int l, int r);
void update(int root, int l, int r, int i, int v);
node query(int root, int l, int r, int i, int j);

int main(){
	
	int q, u;
	char c;
	info *tmp;
	int cont = 0;
	n = 100001;
	scanf("%d", &q);
	build(1, 0 , n-1);
	while(q--){
		scanf(" %c %d", &c, &u);
		if(c=='+'){
			if(m.find(u) == m.end())m[u].posi = cont++;
			tmp = &m[u];
			if(tmp->q == 0)update(1, 0, n-1, tmp->posi, u);
			tmp->q ++;
		}
		else{
			tmp = &m[u];
			if(tmp->q == 1)update(1, 0, n-1, tmp->posi, 0);
			tmp->q--;
		}
		
		printf("%d\n", max(tree[1].val, 1));
	}
	
	return 0;
}

void build(int root, int l, int r){
	if(l == r){
		tree[root].val = 0;
		return;
	}
	int leftChild = root<<1, rightChild = leftChild + 1, mid = (l+r)>>1;
	
	build(leftChild, l, mid);
	build(rightChild, mid+1, r);
	
	tree[root].val = gcd(tree[leftChild].val, tree[rightChild].val);
}
void update(int root, int l, int r, int i, int v){
	if( l > i || i > r)return;
	else if( l == i && i == r){tree[root].val = v;return;}
	int leftChild = root<<1, rightChild = leftChild + 1, mid = (l+r)>>1;
	
	update(leftChild, l, mid, i, v);
	update(rightChild, mid+1, r, i, v);
	
	tree[root].val = gcd(tree[leftChild].val, tree[rightChild].val);
}
