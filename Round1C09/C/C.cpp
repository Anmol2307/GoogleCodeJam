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

vector <int> pris;
int dp[101][101];

int find (int left, int right) {
  if (right - left < 2) return 0;
  if (dp[left][right] != -1) return dp[left][right];

  int ans = INT_MAX;

  for (int i = left + 1; i < right; i++) {
    int val = pris[right] - pris[left] - 2;
    val += find(left, i) + find(i,right);
    ans = min(ans,val);
  }
  return dp[left][right] = ans;
}


int main () {
  int n, k = 1;
  inp(n);

  while (n--) {
    int p, q;
    inp(p); inp(q);
    pris.clear();
    pris.push_back(0);
    pris.push_back(p+1);
    for (int i = 0; i < q; i++) {
      int x; inp(x);
      pris.push_back(x);
    }
    sort(pris.begin(), pris.end());
    memset(dp,-1,sizeof(dp));
    int ans = find(0,pris.size()-1);
    printf("Case #%d: %d\n",k++,ans);
  }
}