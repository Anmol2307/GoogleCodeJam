#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 500

bool vis[N][N];
int dp[N][N];
int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
string s[N];

void dfs(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n){
		return;
	}
	if(vis[x][y] == true){
		return;
	}
	vis[x][y] = true;
	if(dp[x][y] > 0 || s[x][y] == '*'){
		return;
	}
	for(int k = 0; k < 8; k++){
		dfs(x + di[k], y + dj[k]);
	}
}

inline void solve(){
	int i, j, k, x, y, c;
	sd(n);
	for(i = 0; i < n; i++){
		cin>>s[i];
		for(j = 0; j < n; j++){
			vis[i][j] = false;
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			dp[i][j] = 0;
			if(s[i][j] == '*'){
				continue;
			}
			for(k = 0; k < 8; k++){
				x = i + di[k];
				y = j + dj[k];
				if(x >= 0 && x < n && y >= 0 && y < n){
					if(s[x][y] == '*'){
						dp[i][j]++;
					}
				}
			}
		}
	}
	c = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(s[i][j] == '*'){
				continue;
			}
			if(vis[i][j] == false && dp[i][j] == 0){
				dfs(i, j);
				c++;
			}
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(s[i][j] == '*'){
				continue;
			}
			if(vis[i][j] == false){
				c++;
			}
		}
	}
	cout<<c<<endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cn = 0;
	sd(t);
	while(t--){
		cn++;
		cout<<"Case #"<<cn<<": ";
		solve();
	}
    return 0;
}
