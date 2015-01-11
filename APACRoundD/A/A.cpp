#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
      n=0;
      int ch=getchar(),sign=1;
      while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
      while( ch >= '0' && ch <= '9' )
          n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
      n=n*sign;
}
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 1005

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n;
int mat[N][N];
int vis[N][N];

bool isValid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < n;
}

int solve (int i, int j) {
  int ma = 1;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    if (isValid(i+dx[k],j+dy[k]) && vis[i+dx[k]][j+dy[k]] == 0 && abs(mat[i+dx[k]][j+dy[k]] - mat[i][j]) == 1) {
      ma = max(ma,solve(i+dx[k],j+dy[k]) + 1);
    }
  }
  return ma;
}

int main () {
  int t, cases = 1;
  inp(t);

  while (t--) {
    
    inp(n);
    
    
    int dp[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        inp(mat[i][j]);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        memset(vis,0,sizeof vis);
        dp[i][j] = solve(i,j);
      }
    }

    int mv = 0;
    int ma = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] > ma) {
          ma = dp[i][j];
          mv = mat[i][j];
        }
        else if (dp[i][j] == ma && mat[i][j] < mv) {
          mv = mat[i][j];
        }
      }
    }
    printf("Case #%d: %d %d\n",cases++,mv,ma);
  }
}