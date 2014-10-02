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

typedef long long int lli;
typedef vector <int> vi;
typedef pair<int.int> pii;
typedef vector <pii> vpii;

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);
    vpii vec;
    for (int i = 0; i < m; i++) {
      int x; inp(x);
      for (int j = 0; j < x; j++) {
        int y, z;
        inp(y); inp(z);
        vec.push_back(pii(y,z));
      }
    }
    vi ans(n,0);
    for ()
  }
}