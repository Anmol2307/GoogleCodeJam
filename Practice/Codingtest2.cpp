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

typedef pair<int,int> pii;
const int MAXN = 10005;
int tree[MAXN];

int read(int idx){
 int sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
 
void update(int idx ,int val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}


int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    printf("Case #%d: ",k++);
    int n;
    inp(n);
    memset(tree,0,sizeof(tree));

    pii arr[n];
    
    for (int i = 0; i < n; i++) {
      inp(arr[i].first); inp(arr[i].second);
    }

    sort(arr, arr+n);

    int count = 0;
    for (int i = n-1; i >= 0; i--) {
      count += read(arr[i].second - 1);
      update(arr[i].second,1);
    }
    printf("%d\n",count);
  }

}