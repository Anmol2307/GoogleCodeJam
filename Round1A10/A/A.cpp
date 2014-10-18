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

int mx[4]={1,1,1,0},my[4]={-1,0,1,1};

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    printf("Case #%d: ",k++);
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

    bool br = false, bb = false;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++){
        if(rot[i][j]=='.')continue;
        char c=rot[i][j];
        for(int q=0;q<4;q++){
          int ii=i,jj=j;
          int w;
          for(w=0;w<k;w++){
            if(ii<0||ii>=n||jj<0||jj>=n)break;
            if(rot[ii][jj]!=c)break;
            ii+=mx[q];jj+=my[q];
          }
          if(w==k){
            if(c=='R') br=true;
            else if(c=='B') bb=true;
            break;
          }
        }
      }
    }

    if (br && bb) printf("Both\n");
    else if (br) printf("Red\n");
    else if (bb) printf("Blue\n");
    else printf("Neither\n");
  }
}