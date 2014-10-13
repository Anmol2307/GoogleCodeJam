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
#define maxn 1000005
lli dp[maxn];
int arr[10];
vector <vector<int> > factors(maxn);

int check (int num) {
  int sz = 0;
  while (num != 0) {
    if (arr[num%10] == 0) return -1;
    num /= 10;
    sz++; 
  }
  return sz;
}

void sieve() {

  for (int i = 4; i < maxn; i++) {
    for (int j = 2; j*j <= i; j++) {
      if (i%j == 0) {
        factors[i].push_back(j);
        if (j != i/j) factors[i].push_back(i/j);
      }
    }
  }
}

int main () {
  sieve();
  int t, k = 1;
  inp(t);
  while (t--) {
    printf("Case #%d: ", k++);
    for (int i = 0; i < 10; i++) {
      inp(arr[i]);
    }
    int x;
    inp(x);

    // for (int i = 0; i < factors[143].size(); i++) {
    //   printf("%d ",factors[143][i]);
    // }
    // printf("\n");
    // exit(0);
    memset(dp,0,sizeof(dp));
    if (arr[0] == 1) dp[0] = 1;
    else dp[0] = -1;
    if (arr[1] == 1) dp[1] = 1;
    else dp[1] = -1;
    if (arr[2] == 1) dp[2] = 1;
    else dp[2] = -1;
    if (arr[3] == 1) dp[3] = 1;
    else dp[3] = -1;
      
    for (int i = 4; i <= x; i++) {
      dp[i] = 1000000000000000;
      int val = check(i);

      if (val != -1) {
        dp[i] = val;
      }
      for (int j = 0; j < factors[i].size(); j++) {
        int num = factors[i][j];
        if (i%num == 0 && dp[i/num] != -1 && dp[num] != -1) dp[i] = min(dp[i],1+dp[i/num]+dp[num]);
        // if (i == 128) {
        //   printf("%d %d\n",num,dp[i]);
        // }
      }
      if (dp[i] == 1000000000000000) dp[i] = -1;
    }

  
    // for (int i = 4; i <= 60; i++) {
    //   printf("%d %d\n",i,dp[i]);
    // }

    if (dp[x] != -1) printf("%lli\n",dp[x]+1);
    else printf("Impossible\n");
  }
}