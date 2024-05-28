#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;

ll dp[1 << MAX_N][MAX_N];
// come_from[i] contains the cities that can fly to i
vector<int> come_from[MAX_N];

int main() {
	int city_num;
	int flight_num;
	cin >> city_num >> flight_num;
	for (int f = 0; f < flight_num; f++) {
		int start, end;
		cin >> start >> end;
		come_from[--end].push_back(--start);
	}

	dp[1][0] = 1; // everything else initialized as 0
	for (int mask = 1; mask < (1<<city_num); mask++) { // mask, states of cities visited
		if ((mask & (1 << 0)) == 0) continue; // if does not contain first city, skip
		if ( (mask & (1 << (city_num - 1))) && mask != ((1 << city_num) - 1) ) continue;
		// if contains the last city       but mask is not full (visited all cities), skip
													// (1 << city_num)-1 -> the full city mask
		// 1<<(city_num - 1) -> highest digit in the mask

		for (int city = 0; city < city_num; city++) {
			if ((mask & (1 << city)) == 0) continue; 
			// for each possible mask, check if this 'city' is reachable in this mask combination

			int prev = mask - (1 << city);  //use subset that does not contain the current city
			for (int j : come_from[city]) {  // j: everything that goes to this [city]
				//if ((mask & (1 << j))) {
					dp[mask][city] += dp[prev][j];
					dp[mask][city] %= MOD;
				//}
			}
		}
	}
	cout << dp[(1 << city_num) - 1][city_num - 1];
}