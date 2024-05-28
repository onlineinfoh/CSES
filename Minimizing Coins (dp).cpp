#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int coinChange(vector<int>& coins, int amount) {
	vector<ll> dp(1000004);
	for(ll a = 0; a<= 1000003; a++) dp[a] = -1;
	dp[0] = 0;

	for(ll a = 1; a<=1000003; a++){
		//if (a!=0 && dp[a] == -1) continue;
		for(int num: coins){
			if(a-num>=0 && dp[a-num] != -1)
			dp[a] = dp[a] == -1 ? dp[a-num] +1 : min(dp[a], dp[a-num]+1);
		}
	}

	return dp[amount];
}

int main() {
	int want, len;
	cin>>len>>want;
	vector<int>vec(len);
	for(int a = 0; a< len; a++){
		cin>>vec[a];
	}
	cout<<coinChange(vec, want);
}
