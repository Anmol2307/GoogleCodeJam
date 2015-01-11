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
#define N 5005

int arr[N];

int main () {
  int t, cases = 1;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    memset(arr,0,sizeof arr);
    for (int i = 0; i < n; i++) {
      int a, b;
      inp(a); inp(b);
      for (int j = a; j <= b; j++) {
        arr[j]++;
      }
    }
    int p;
    inp(p);
    printf("Case #%d: ",cases++);
    for (int i = 0; i < p; i++) {
      int x; inp(x);
      printf("%d ",arr[x]);
    }
    printf("\n");
  }
}