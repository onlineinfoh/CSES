#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree(4*200005);
vector<ll> vec(200005);

void build(ll cur, ll start, ll end){
	if(start==end){
		tree[cur] = vec[start];
	}
	else{
		ll m = (start+end)/2;
		build(cur*2, start, m);
		build(cur*2+1, m+1, end);
		tree[cur] = tree[cur*2]+tree[cur*2+1];
	}
}

void update(ll cur, ll start, ll end, ll changePos, ll changeVal){
	if(start==end){
		tree[cur] = changeVal;
	}
	else{
		ll m = (start+end)/2;
		if(changePos<=m)
			update(cur*2, start, m, changePos, changeVal);
		else 
			update(cur*2+1, m+1, end, changePos, changeVal);
		tree[cur] = tree[2*cur]+tree[2*cur+1];
	}
}

ll sum(ll cur, ll start, ll end, ll l, ll r){
	if(l>r) return 0;
	if(start == l && end == r) return tree[cur];
	ll m = (start+end)/2;
	return sum(cur*2, start, m, l, min(m, r))+sum(cur*2+1, m+1, end, max(m+1, l), r);
}

int main() {
	ll len, cases; cin>>len>>cases;
	for(ll a = 0; a< len; a++) cin>>vec[a];
	build(1, 0, len-1);
	for(ll a = 0; a< cases; a++){
		ll choice, l, r;
		cin>>choice>>l>>r;
		if(choice == 1) update(1, 0, len-1, l-1, r);
		else cout<<sum(1, 0, len-1, l-1, r-1)<<endl;
	}
	//for(int a = 0; a< len*4; a++) cout<<tree[a]<<" ";
}