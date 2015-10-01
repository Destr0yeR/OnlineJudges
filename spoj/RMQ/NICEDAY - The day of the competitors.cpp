#include<bits/stdc++.h>
#define MAX 25
#define identity 0
using namespace std;

int n;
int A[1<<(MAX-1)];

struct node{
	bool pendiente;
	int val, l, r, updated;
	node(){l = -1; r = -1 ; val = identity; updated = 0; pendiente = false;}
	node(int left, int right){l = left; r = right; val = identity; updated = 0; pendiente = false;}
	node(int left, int right, int value){l = left; r = right; val = value; updated = 0; pendiente = false;}
	
	void split(node&a , node& b){
		a.pendiente = true;
		a.updated += updated;
		b.pendiente = true;
		b.updated += updated;
		pendiente = false;
		val += updated;
		updated = 0;
	}
	
	void merge(node&a , node& b){
		val = max(a.val, b.val);
	}
}tree[1<<MAX];

node query(int root, int l, int r, int u, int v){
	int leftChild = root<<1 , rightChild = leftChild+1, mid = (l+r)>>1;
	if(u <= l && r <= v){
		if (tree[root].pendiente) tree[root].split(tree[leftChild], tree[rightChild]);
		return tree[root];
	}
	else if(r < u || v < l)return node();
	
	if (tree[root].pendiente) tree[root].split(tree[leftChild], tree[rightChild]);
	
	node a = query(leftChild, l, mid, u, v);
	node b = query(rightChild, mid+1, r, u, v);
	node tmp;
	tmp.merge(a, b);
	return tmp;
}

int query_value(int i, int j){
	return query(1, 0, n-1, i, j).val;
}

void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(l, r, A[l]);
		return;
	}
	
	int leftChild = root<<1 , rightChild = leftChild+1, mid = (l+r)>>1;
	
	build(leftChild, l, mid);
	build(rightChild, mid+1, r);
	
	tree[root] = node(l, r);
	tree[root].merge(tree[leftChild], tree[rightChild]);	
}

void update(int root, int l, int r, int u, int v, int value){
	int leftChild = root<<1, rightChild = leftChild+1, mid = (l+r)>>1;
	if(u <= l && r <= v){
		tree[root].pendiente = true;
		tree[root].updated += value;
		tree[root].split(tree[leftChild], tree[rightChild]);
		return;
	}
	if(r < u || v < l)return;
	else{		
		update(leftChild, l, mid, u, v, value);
		update(rightChild, mid+1, r, u, v, value);
		tree[root].merge(tree[leftChild], tree[rightChild]);
	}
}

void update_value(int i, int j, int value)
{
    update(1, 0, n-1, i, j, value);
}

int main(){
	int T, u, v, q, res;
	scanf("%d", &T);
	n = 10000000;
	int maxi;
	while(T--){
		maxi = 0;
		scanf("%d", &q);
		memset(A, 0, sizeof(A));
		build(1, 0, n-1);
		for(int i = 0 ; i < q ; ++i){
			scanf("%d %d", &u, &v);
			u--;v--;
			maxi = max(v, maxi);
			update(1, 0, n-1, u, v, 1);
		}
		res = query_value(0, n-1);
		printf("%d\n", res);
	}
	
	return 0;
}
