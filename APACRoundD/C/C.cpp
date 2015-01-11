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
string orig, dest;

int main () {
  int t, k = 1;
  inp(t);
  int n;
  while (t--) {
    printf("Case #%d: ", k++);

    map<string, string> m;
    map<string, bool> m2;
    inp(n);
    for (int i = 0; i < n; i++) {
      getline(cin, orig);
      getline(cin, dest);
      m[orig] = dest;
      m2[dest] = 1;
    }
    for (map<string, string>::iterator it=m.begin(); it!=m.end(); ++it) {
      if (m2.find(it->first) == m2.end()) {
        orig = it->first;
        break;
      }
    }

    for (int i = 0; i < n - 1; i++) {
      printf("%s-%s ", orig.c_str(), m[orig].c_str());
      orig = m[orig];
    }
    printf("%s-%s\n", orig.c_str(), m[orig].c_str());
  }
}