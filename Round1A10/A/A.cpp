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

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    // printf("Case #%d: ",k++);
    int n, k;
    inp(n); inp(k);
    
    vector <string> vec(n);

    for (int i = 0; i < n; i++) {
      string str;
      getline(cin,str);
      vec[i] = str;
    }

    char rot[n][n];

    int indy = n-1;
    for (int i = 0; i < n; i++) {
      int indx = n-1;
      for (int j = n-1; j >= 0; j--) {
        if (vec[i][j] != '.') {
          rot[indx--][indy] = vec[i][j];
        }
      }
      for (int i = 0; i <= indx; i++) {
        rot[i][indy] = '.';
      }
      indy--;
    }

    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     printf("%c",rot[i][j]);  
    //   }
    //   printf("\n");
    // }

    bool br = false, bb = false;
    for (int i = 0; i < n; i++) {
      int cr = 0, cb = 0;
      for (int j = 0; j < n; j++) {
        if (rot[i][j] == 'R') cr++;
        else if (rot[i][j] == 'B') cb++;
      }
      if (cr >= k) br = true;
      if (cb >= k) bb = true;
    }
    if (br && bb) printf("Both\n");
    else if (br) printf("Red\n");
    else if (bb) printf("Blue\n");
    else printf("Neither\n");
  }
}