#include<bits/stdc++.h>

#define MAX 18
#define identity_sum 0
#define identity_mn (1<<29)

using namespace std;

int n, max_tree, A[1 <<(MAX-1)];

struct node{
	int l, r, val, mn;
	
	node(){l = -1;r = -1;val = identity_sum; mn = identity_mn;}
	node(int left, int right){l = left;r = right;val = identity_sum; mn = identity_mn;}
	node(int left, int right, int value){l = left;r = right;val = value; mn = identity_mn;}
	node(int left, int right, int value, int min){l = left;r = right;val = value;mn = min;}
	
	void merge(node& a, node& b){
		val = a.val + b.val;
		mn = min(a.mn, a.val + b.mn);
	}
}tree[1<<MAX];

void update(int root, int l, int r, int u);

void update_value(int i){
	update(1, 0, n-1, i);
}

void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(l, r, A[l], A[l]);
		return;
	}
	
	int leftChild = root*2, rightChild = leftChild+1, mid=(l+r)>>1;
	
	build(leftChild, l, mid);
	build(rightChild, mid+1, r);
	
	tree[root] = node(l, r);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}

node query(int root, int l, int r, int u, int v){
	if(u <= l && r <= v){
		return tree[root];
	}
	else if( u > r || l > v)return node();
	
	int leftChild = root*2, rightChild = leftChild+1, mid=(l+r)>>1;
	
	node a = query(leftChild, l, mid, u, v);
	node b = query(rightChild, mid+1, r, u, v);
	node tmp;
	tmp.merge(a, b);
	return tmp;
}

int query_value(int i, int j){
	return query(1, 0, n-1, i, j).val;
}

int main(){
	
	int T = 10, m, q;
	char c;
	node res;
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> n;
		for(int i = 0 ; i < n ; ++i){
			cin >> c;
			A[i] = (c=='('?1:-1);
		}
		build(1, 0, n-1);
		cin >> m;
		cout << "Test " << tc << ":" << endl;
		
		for(int i = 0 ; i < m ; ++i){
			cin >> q;
			if(q){
				update_value(q-1);
			}
			else{
				res = query(1,0, n-1, 0, n-1);
				if(!res.val && !res.mn)cout<<"YES";
				else cout <<"NO";
				cout << endl;
			}
		}
	}
	
	return 0;
}

void update(int root, int l, int r, int u){
	if(l == u && l == r){
		tree[root].val = tree[root].val*-1;
		tree[root].mn = tree[root].val;
		return;
	}
	if( u < l || u > r)return;
	
	int leftChild = root*2, rightChild = leftChild+1, mid=(l+r)>>1;
	
	update(leftChild, l, mid, u);
	update(rightChild, mid+1, r, u);
	
	tree[root].merge(tree[leftChild], tree[rightChild]);
}
