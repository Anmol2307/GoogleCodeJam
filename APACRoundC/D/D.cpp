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
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

int main () {
  int t, k = 1;

  while (t--) {
    printf("Case #%d: ", k++);
    
  }
}