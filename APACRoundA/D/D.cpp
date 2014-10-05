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
typedef pair<int,int> pii;

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);

    int arr[n];

    for (int i = 0; i < n; i++) {
      int x; inp(x);
      arr[i] = 1<<x;
    }

    sort(arr, arr+n);
    reverse(arr,arr+n);
    
    queue<pii> Q;
    int ans = 0;
    int visited[n];
    memset(visited,0,sizeof(visited));

    while (1) {
      ans++;  
      Q.push(pii(m,m));

      while (!Q.empty()) {
        pii p = Q.front();
        Q.pop();

        for (int i = 0; i < n; i++) {
          if (!visited[i]) {
            if (arr[i] <= p.first && arr[i] <= p.second) {
              visited[i] = 1;
              Q.push(pii(p.first - arr[i],p.second));
              Q.push(pii(arr[i],p.second- arr[i]));
              break;
            }
          }
        }
      }
      bool flag = false;
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          flag = true;
          break;
        }
      }
      if (flag) continue;
      else break;
    }
    printf("Case #%d: %d\n",k++,ans);
  }
}