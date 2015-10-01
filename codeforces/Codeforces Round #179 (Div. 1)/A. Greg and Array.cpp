#include<bits/stdc++.h>
#define MAX 18
#define identity 

using namespace std;

int A[1<<(MAX-1)];

struct 

struct node{
	int l, r, val;
	
	node(){l = -1; r=-1, val = identity;}
	node(int left, int right){l = left; r = right; val = identity;}
	node(int left, int right, int value){l = left; r = right ; val = value;}
	
	void merge(node& a, node &b){
		
	}
	
	void split(node& a, node &b){
		
	}
	
}tree[1<<MAX];

void build(int root, int l, int r);
node query(int root, int l, int r, int i, int j);
void update(int root, int l, int r, int i, int j, int v);

int main(){
	
	return 0;
}

node query(int root, int l, int r, int i, int j){
	int leftChild = root<<1, rightChild = leftChild+1, mid = (l+r)>>1;
	if( i <= l && r <= j){
		if(tree[root].update)tree[root].split(tree[leftChild], tree[rightChild]);
		return tree[root];
	}
	if( j < l || r < i)return node();
	
	node a = query(leftChild, l, mid, i, j);
	node b = query(rightChild, mid+1/, r, i, j);
	
	node tmp;
	tmp.merge(a, b);
	return tmp;
}

void update(int root, int l, int r, int i, int j, int v){
	if( i <= l && r <= j){
		return;
	}
}

void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(l, r, A[l]);
		return;
	}
	
	int leftChild = root<<1, rightChild = leftChild+1, mid = (l+r)>>1;
	build(leftChild, l, mid);
	build(rightChild, mid+1, r);
	tree[root] = node(l, r);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}
