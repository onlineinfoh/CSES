#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1<<20][20];

const ll mod = 1e9+7;

vector<vector<ll>> conn(21);

int main() {
	dp[1][0] = 1;
	// a to b one-way
	int len; cin>>len;
	int t; cin>>t;
	for(int a = 0; a< t; a++){
		ll start; cin>>start;
		ll end; cin>>end;
		conn[--end].push_back(--start);
	}
	for(int mask = 0; mask< (1<< len); mask++){
		if((mask&1) == 0) continue;
		if( (mask&(1<<(len-1))) ==1 && mask!=((1<<len)-1)) continue;
		for(int city = 0; city< len; city++){
			if( (mask&(1<<city)) == 0) continue;
			int prev = mask-(1<<city);
			for(ll from : conn[city]){
				if(mask&(1<<from))
				dp[mask][city] += dp[prev][from];
				dp[mask][city]%=mod;
			}
		}
	}
	cout<< dp[(1<<len)-1][len-1];
}
