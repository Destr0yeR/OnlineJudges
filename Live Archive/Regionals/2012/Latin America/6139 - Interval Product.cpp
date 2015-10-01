#include <bits/stdc++.h>
#define MAX 18
using namespace std;

int n, max_tree;
int A[1 << (MAX-1)];

struct node{
	int l, r, val;
	node(){l = -1;r = -1;val = 1;}
	node(int left, int right){l = left; r = right;val=1;}
	node(int left, int right, int value){
		l = left;
		r = right;
		val = value;
		if(val>0)val=1;
		else if(val<0)val=-1;
	}
	
	void merge(node& a, node& b){
		val = a.val * b.val;
		if(val>0)val=1;
		else if(val<0)val=-1;
	}
}tree[1 << MAX];

node query(int root, int l, int r, int u, int v){
	if( u <= l && r <= v)return tree[root];
	else if( v < l || u > r)return node();
	
	int leftChild = root*2, rightChild = leftChild +1, mid=(l+r)>>1;
	node a = query(leftChild, l, mid, u, v);
	node b = query(rightChild, mid+1, r, u, v);
	node tmp;
	tmp.merge(a, b);
	return tmp;
}

int query_value(int i, int j){
	return query(1, 0, n-1, i, j).val;
}

void update(int root, int l, int r, int u, int value){
	if(l == u && l == r){
		tree[root].val=value;
		return;
	}
	else if( l > u || r < u)return;
	
	int leftChild = root*2, rightChild = leftChild + 1, mid=(l+r)>>1;
	update(leftChild, l, mid, u, value);
	update(rightChild, mid+1, r, u, value);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}

void update_value(int i, int value){
	if(value>0)value=1;
	else if(value<0)value=-1;
	update(1, 0, n-1, i, value);
}

void build(int root, int l, int r){
	if(r == l){
		tree[root]=node(l,r,A[l]);
		return;
	}
	
	int leftChild = root*2, rightChild = leftChild + 1, mid=(l+r)>>1;
	build(leftChild, l, mid);
	build(rightChild, mid+1, r);
	tree[root] = node(l, r);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}

int main(){
	int k;
	while(cin >> n >> k){
		for(int i = 0 ; i < n; ++i){
			cin >> A[i];
		}
		int expo = ceil(log2(n));
		max_tree = 1 << (expo+1);
		build(1, 0, n-1);
		char c;
		int u, v, res;
		for(int i = 0 ; i < k; ++i){
			cin >> c >> u >> v;
			u--;
			if(c == 'C'){
				update_value(u,v);
			}
			else{
				v--;
				res = query_value(u,v);
				if(res > 0)cout<<"+";
				else if(res < 0)cout<<"-";
				else cout<<"0";
			}
		}
		cout << endl;
	}
	
	return 0;
}
