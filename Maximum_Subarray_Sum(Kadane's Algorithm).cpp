// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int len; cin>>len;
	vector<int> nums(len);
	for(int a = 0; a< len; a++) cin>>nums[a];

	ll maxSum = -1e9-5;
	ll curSum = 0;

	for(int a = 0; a< len; a++){
		curSum+=nums[a];
		maxSum = max(maxSum, curSum);
		curSum = curSum<0 ? 0 : curSum;
	}

	cout<<maxSum;
}
