#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 112345678
#define MOD 1000000007
#define D double
#define LD long double

#define N 100000

priority_queue< pair<int, int> > Q;
map< pair<int, int> , int > sid, sid2;
int dis[N];
bool vis[N];
vector< pair<int, int> > adj[N];

inline void solve(){
	int n, i, j, w, m, q, sn, u, v, u2, v2, id, ti, m1, s1, m2, s2;
	sd(n);
	id = 0;
	sid.clear();
	sid2.clear();
	for(i = 0; i < N; i++){
		adj[i].clear();
	}
	for(i = 1; i <= n; i++){
		sd(sn); sd(w);
		u = id;
		for(j = 1; j <= sn; j++){
			adj[id + 1].PB(MP(id, w));
			sid[MP(i, j)] = id;
			id++;
			sid2[MP(i, j)] = id;
			id++;
		}
		for(j = 1; j < sn; j++){
			sd(ti);
			u = sid[MP(i, j)];
			v = u + 2;
			adj[u].PB(MP(v, ti));
			adj[v].PB(MP(u, ti));
		}
	}
	sd(m);
	while(m--){
		sd(m1); sd(s1); sd(m2); sd(s2); sd(ti);
		u = sid[MP(m1, s1)];
		v = sid[MP(m2, s2)];
		u2 = u + 1;
		v2 = v + 1;
		adj[u].PB(MP(v2, ti));
		adj[u2].PB(MP(v2, ti));
		adj[v].PB(MP(u2, ti));
		adj[v2].PB(MP(u2, ti));
	}
	sd(q);
	while(q--){
		sd(m1); sd(s1); sd(m2); sd(s2);
		for(i = 0; i < id; i++){
			dis[i] = INF;
			vis[i] = false;
		}
		u = sid[MP(m1, s1)] + 1;
		Q.push(MP(0, u));
		dis[u] = 0;
		while(!Q.empty()){
			u = (Q.top()).S;
			Q.pop();
			if(vis[u] == true){
				continue;
			}
			vis[u] = true;
			for(j = adj[u].size() - 1; j >= 0; j--){
				v = adj[u][j].F;
				w = adj[u][j].S;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					Q.push(MP(-dis[v], v));
				}
			}
		}
		v = sid[MP(m2, s2)];
		v2 = v + 1;
		if(vis[v] == true || vis[v2] == true){
			printf("%d\n", min(dis[v], dis[v2]));
		}
		else{
			printf("-1\n");
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cn = 0;
	sd(t);
	while(t--){
		cn++;
		cout<<"Case #"<<cn<<":"<<endl;
		solve();
	}
    return 0;
}
