#include<bits/stdc++.h>

#define MAX 18
#define MAXIMUX 247777777

using namespace std;

int n, max_tree, A[1 << MAX];

struct node{
	int l, r, val;
	void split(node& a, node& b){}
	void merge(node& a, node& b)
	{
		val = ( a.val+ b.val );
	}
	node(){
		l = -1;
		r = -1;
		val = MAXIMUX;
	}
	node(int left, int right){
		l = left;
		r = right;
		val = MAXIMUX;
	}
	node(int left, int right, int value){
		l = left;
		r = right;
		val = value;
	}
}tree[1<<MAX];

node identity;

node query(int root, int l, int r, int u, int v){
	if( l >= u && v >= r) return tree[root];
	else if( v < l || u > r) return node();
	else{
		int leftChild = root*2, rightChild = leftChild+1, mid = (l+r)>>1;
		node a = query(leftChild, l, mid, u, v);
		node b = query(rightChild, mid+1, r, u, v);
		node tmp;
		tmp.merge(a,b);
		return tmp;
	}
}

int query_value(int i, int j){
	return query(1, 0, n-1, i, j).val;
}

void build(int root, int l, int r){
	if(l == r){
		tree[root] = node(l, r, A[l]);
		return;
	}
	
	int leftChild = root*2, rightChild = leftChild+1, mid = (l+r)>>1;
	build(leftChild, l, mid);
	build(rightChild, mid+1, r); 
	
	tree[root] = node(l, r);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}

void update(int root, int l, int r, int u, int value){
	if(l == u && l == r)tree[root].val = value;
	else if( l > u || u > r)return;
	else {
		int leftChild = root*2, rightChild = leftChild+1, mid = (l+r)>>1;
		update(leftChild, l, mid, u, value);
		update(rightChild, mid+1, r, u, value);
		tree[root].merge(tree[leftChild], tree[rightChild]);
	}
}

void update_value(int i, int value)
{
    update(1, 0, n-1, i, value);
}
vector<int> F(41);
void fibo(){
	int i=2;
	F[0]=1;
	F[1]=1;
	for(;i<41;i++){
		F[i]=F[i-1]+F[i-2];
	}
}
int isSumOfFibo(int n){
	if(n==1) return 0;
	if(n==2) return 1;
	vector<int>::iterator it;
	int a,b;
	it=lower_bound(F.begin(),F.end(),n);
	a=*it;
	it=lower_bound(F.begin(),F.end(),F[a]);
	b=*it;
	cout<<a<<" "<<b<<endl;
	cout<<F[a]<<" "<<F[b]<<endl;
	if((F[a]+F[b])==n) return 1;
	return 0;
}
int main(){
	fibo();
	for(int i=0;i<40;i++){cout<<F[i]<<endl;}
	cout<<"hola"<<endl;
	cout<<isSumOfFibo(10)<<endl;
	int n,q,x;
	
	identity.val = MAXIMUX;
	scanf("%d %d",&n,&q);
	int expo = ceil(log2(n));
	max_tree = 1 << (expo+1) ;
	for(int i = 0 ; i < n ; ++i){
		cin >> x;
		A[i]=isSumOfFibo(x);
	}
	
	build(1, 0, n-1);
	
	int u, v;
	
	while(cin >> q >> u >> v){
		if(q == 1){
			cout << query_value(u,v) << endl;
		}
		else{
			update_value(u,v);
		}
	}
	
	
	return 0;
}
