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
typedef pair< int, pii > pip;
typedef pair< int, ll > pil;
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
#define N 90
#define MOD 1000000007

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    int gp, gc, gf;
    inp(gp);inp(gc);inp(gf);

    int n;
    inp(n);

    vector<pip> vec;

    for (int i = 0; i < n; i++) {
      int x, y, z;
      inp(x); inp(y); inp(z);
      vec.push_back(pip(x,pii(y,z)));
    }
    int tot = 1 << n;
    
    bool flag = false;
    for (int i = 1; i < tot; i++) {
      int totx = 0, toty = 0, totz = 0;
      for (int j = 0; j < n; j++) {
        if ((i>>j)&1) {
          totx += vec[j].ff;
          toty += vec[j].ss.ff;
          totz += vec[j].ss.ss;
        }
      }
      if (totx == gp && toty == gc && totz == gf) {
        printf("Case #%d: yes\n",k++);
        flag = true;
        break;
      }
    }
    if (!flag) {
      printf("Case #%d: no\n",k++);
    }
  }
}