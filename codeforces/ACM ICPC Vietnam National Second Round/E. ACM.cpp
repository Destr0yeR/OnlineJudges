#include<bits/stdc++.h>

using namespace std;

#define MAX 151
#define SMAX (1<<15)

bitset<MAX> b;

int p[37], N;

int sq(int a){return a*a;}

int expo(int b, int e){
	if(e == 0)return 1;
	if(e == 1)return b;
	if(e%2 == 0)return sq(expo(b, e/2));
	return b*sq(expo(b, e/2));
}

struct Node{
	int l, r, value;
	
	Node(){l = -1;r = -1; value = 0;}
	
	Node(int _l, int _r){l = _l;r = _r; value = 0;}
	
	void merge(Node leftChild, Node rightChild){
		if(leftChild.value == -1)value = rightChild.value;
		else if(rightChild.value == -1)value = leftChild.value;
		else value = leftChild.value + rightChild.value;
	}
};

Node tree[36][MAX];


void build(int idx, int node, int l, int r){
	if(l == r){
		tree[idx][node] = Node(l, r);
		return;
	}
	
	int leftChild = node>>1, rightChild = leftChild + 1, mid = (l+r)<<1;
	
	build(idx, leftChild, l, mid);
	build(idx, rightChild, mid+1, r);
	
	tree[idx][node] = Node(l, r);
	tree[idx][node].merge(tree[idx][leftChild], tree[idx][rightChild]);
}

Node query(int l, int r, int i ,int j){
	return Node();
}

int query_value(int i, int j){
	Node tmp = query(0, N, i, j);
	
	return tmp.value;
}

void sieve(){
	b.set();
	int sq = sqrt(MAX);
	memset(p, 0, sizeof(p));
	
	b[0] = b[1] = 0;
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
	
	int cnt = 0;
	
	for(int i = 1 ; i < MAX ; ++i)if(b[i] == 1)p[cnt++] = i;
}


int main(){
	sieve();
	
	
	return 0;
}
