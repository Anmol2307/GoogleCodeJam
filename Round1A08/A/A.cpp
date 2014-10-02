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


int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    vector <lli> vec1;
    vector <lli> vec2;

    for (int i = 0; i < n; i++) {
      lli x;
      scanf("%lli",&x);
      vec1.push_back(x);
    }

    for (int i = 0; i < n; i++) {
      lli x;
      scanf("%lli",&x);
      vec2.push_back(x);
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    reverse(vec2.begin(), vec2.end());

    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += vec1[i]*vec2[i];
    }
    printf("Case #%d: %lli\n",k,ans);
    k++;
  }
}