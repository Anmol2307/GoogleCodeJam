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
#define maxn 7
int mat[1<<maxn][1<<maxn];
int n;

bool row_valid () {
  int sz = n*n;

  for (int i = 0; i < sz; i++) {
    int arr[sz+1];
    memset(arr,0,sizeof(arr));
    for (int j = 0; j < sz; j++) {
      if (arr[mat[i][j]] == 0) arr[mat[i][j]] = 1;
      else return false;
    }
  }
  return true;
}

bool column_valid () {
  int sz = n*n;

  for (int j = 0; j < sz; j++) {
    int arr[sz+1];
    memset(arr,0,sizeof(arr));
    for (int i = 0; i < sz; i++) {
      if (arr[mat[i][j]] == 0) arr[mat[i][j]] = 1;
      else return false;
    }
  }
  return true;
}

bool square_valid() {
  int sz = n*n;

  for (int i = 0; i < sz; i+=n) {
    for (int l = 0; l < sz; l+= n) {
      for (int j = i; j < i+n; j++) {
        int arr[sz+1];
        memset(arr,0,sizeof(arr));
        for (int k = l; k < l+n; k++) {
          if (arr[mat[j][k]] == 0) arr[mat[j][k]] = 1;
          else return false;
        }
      }
    }
  }
  return true;
}


int main () {
  int t, k= 1;
  inp(t);

  while (t--) {
    printf("Case #%d: ",k++);
    inp(n);

    int sz = n*n;
  
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        inp(mat[i][j]);
      }
    }

    if (row_valid() && column_valid() && square_valid()) printf("Yes\n");
    else printf("No\n");
  }
}