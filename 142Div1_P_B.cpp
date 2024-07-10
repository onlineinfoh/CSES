#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, len; cin>>n>>len;
	vector<vector<pair<ll, ll>>> adj(n+1); //<travel_to, time taken>
	for(int a = 0; a< len; a++){
		ll one, two, t;  cin>>one>>two>>t;
		adj[one].push_back(make_pair(two, t));
		adj[two].push_back(make_pair(one, t));
	}
	vector<ll> time(n+1, 9e18);
	vector<set<ll>> time_with_ppl(n+1);
	for(int i = 1; i<=n; i++){
		int t; cin>>t;
		ll num;
		while(t--){
			cin>>num; time_with_ppl[i].insert(num);
		}
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //<time, curNode>

	time[1] = 0;
	pq.push({0, 1});

	while(!pq.empty()){
		ll curTime= pq.top().first;
        ll curNode = pq.top().second;
        pq.pop();

		if (curTime > time[curNode])
            continue;

		while(time_with_ppl[curNode].find(curTime) != time_with_ppl[curNode].end()){
			curTime++;
		}

        for(auto it: adj[curNode]){
            if(curTime+it.second < time[it.first]){
                time[it.first] = curTime+it.second;
                pq.push({time[it.first], it.first});
            }
        }
    }
	cout<<(time[n] == 9e18 ? -1 : time[n]);
}